package idv.example.anr;
import idv.example.anr.utils.*;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.LinearLayout;
import android.widget.ImageView;
import android.view.View;
import android.content.Context;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.BitmapFactory;
import android.graphics.Paint;
import android.graphics.Color;
import android.graphics.PorterDuffColorFilter;
import android.graphics.PorterDuff.Mode;
import android.graphics.PorterDuff;
import android.graphics.AvoidXfermode;
import android.graphics.PixelXorXfermode;
import android.graphics.PorterDuffXfermode;


import android.graphics.Matrix;
import android.widget.*;
import android.widget.Gallery.LayoutParams;
import android.widget.ImageView.ScaleType; 
import android.util.Log; 

class MyImageView extends ImageView
{
	Context LocalContext         = null;
	Bitmap holderBitmap          = null;
	Bitmap [] destBitmap 	     = null;
	Bitmap backgroundBitmap      = null;
	Bitmap scaleBackgroundBitmap = null;
	String errorMessage       = "No Picture";
	String strHelloWorld      = "Hello World!!!!";
	static String debugName   = "TestImageView";
	int id = 0;
	int viewWidth = 0;
	int viewHeight = 0;
	boolean mAdjustViewBounds = false; 
	int drawPtr = 0;
	SpriteDescription[] _sd = null;
	SpriteDescription[] _maxHeightSd = new SpriteDescription[1] ;
	SpriteDescription[] _maxWidthSd  = new SpriteDescription[1] ;
	int backgroundColor = Color.DKGRAY;
	int textColor  = Color.WHITE;
	SpriteLocation [] _sl = null;
	int bottomPadding = 15;
	//-------------------------------------------------------------
	// preprocessor function
	public static Bitmap __spirteBitmap(Bitmap src, SpriteLocation sl, SpriteDescription sd )
	{
		if ( src == null ) return null;
		if ( sd  == null ) return null;

 		Matrix matrix=new Matrix();
       	matrix.postScale(1.0f, 1.0f);
		return Bitmap.createBitmap ( src, sl.getX(), sl.getY(), sd.getWidth(), sd.getHeight(), matrix, false );
	}	
	public static void fillTransparentColor( Bitmap bmp, SpriteDescription sd, int replaceColor )
	{
		int x = 0, y = 0;
		if ( bmp == null ) return;
		if ( sd  == null ) return;
		for( x = 0 ; x < sd.getWidth() ; x++ )
		{
			for ( y = 0 ; y < sd.getHeight() ; y++ )
			{
				if ( replaceColor == bmp.getPixel( x, y ) )
				{
					bmp.setPixel( x, y, Color.TRANSPARENT );
				}
			}
		}
	}
	private void findMaxSpriteDescription( 
		SpriteDescription[] sd, 
		SpriteDescription[] maxWidthSd, 
		SpriteDescription[] maxHeightSd )
	{
		if ( sd == null ) return;

		maxHeightSd[0] = sd[0];
		maxWidthSd[0]  = sd[0];
		if ( maxHeightSd[0] == null ) return;
		if ( maxWidthSd[0]  == null ) return;
		for ( int i = 1 ; i < sd.length ; i ++ ) {
			if ( sd[i].getHeight() > maxHeightSd[0].getHeight() )
			{
				maxHeightSd[0] = sd[i];
			}
			if ( sd[i].getWidth() > maxWidthSd[0].getWidth() )
			{
				maxWidthSd[0] = sd[i];
			}
		}
		
	}
	//--------------------------------------------------------------
	public void AddBitmap( int resId, SpriteLocation[] sl, SpriteDescription[] sd ) 
	{
		if ( LocalContext == null ) return;
		if ( sd == null ) return;
		if ( sl == null ) return;
		id = resId;
		holderBitmap = BitmapFactory.decodeResource( LocalContext.getResources(), id );	
		if ( holderBitmap == null ) return;

		this._sd = sd;
		this._sl = sl;
		findMaxSpriteDescription ( this._sd, this._maxWidthSd, this._maxHeightSd );

		destBitmap = new Bitmap[ this._sl.length ];
		for ( int i = 0 ; i < destBitmap.length ; i ++ ) {
			destBitmap[i] =  this.__spirteBitmap ( holderBitmap, this._sl[i] , this._sd[i] );
			this.fillTransparentColor( destBitmap[i], this._sd[i], Color.WHITE );
		}
	}	
	public MyImageView(Context context){
		super(context);
		LocalContext = context;
	}
	//--------------------------------------------------------------------------------------------------
	private int [] draw_x = { 0 } ;
	private int [] draw_y = { 0 } ;
	public enum INCREASE_DIRECTION {
		POSITIVE, NEGATIVE;
	};
	private INCREASE_DIRECTION [] incDirection       = { INCREASE_DIRECTION.POSITIVE };
	private INCREASE_DIRECTION [] incDirection_y     = { INCREASE_DIRECTION.POSITIVE };

	private void calculateNext(int[] prevV, int range, int len, INCREASE_DIRECTION[] dir )
	{
		int tmp = prevV[0];
		if ( dir[0] == INCREASE_DIRECTION.POSITIVE )
			tmp += (int)( range/60 );

		if ( dir[0] == INCREASE_DIRECTION.NEGATIVE )
			tmp -= (int)( range/60 );

		if ( tmp > range - len )
			dir[0] = INCREASE_DIRECTION.NEGATIVE;

		if ( tmp < 0 )
			dir[0] = INCREASE_DIRECTION.POSITIVE;

		if ( tmp <= 0 ) tmp = 0 ;
		prevV[0] = tmp;
	}
	private void CalculateNextDrawX() 
	{
		this.calculateNext ( draw_x, viewWidth, this._sd[drawPtr].getWidth(), incDirection );
	}

	private void CalculateNextDrawY()
	{
		this.calculateNext ( draw_y, viewHeight, this._sd[drawPtr].getHeight()+ bottomPadding , incDirection_y );
	}

	private int [] draw_text_x = { 0 } ;
	private INCREASE_DIRECTION [] incDirection_text_x= { INCREASE_DIRECTION.POSITIVE };
	private void CalculateNextTextDrawX() {
		this.calculateNext ( draw_text_x, viewWidth, strHelloWorld.length()*10 , incDirection_text_x);
	}
	// override 
	@Override
	protected void onDraw(Canvas canvas){
		super.onDraw(canvas);
		if ( this.destBitmap == null ) return;

		canvas.drawColor( Color.TRANSPARENT ); 
		if ( this.backgroundBitmap != null ) 
		{
			if ( this.scaleBackgroundBitmap == null )
			{
				this.scaleBackgroundBitmap = 
					Bitmap.createScaledBitmap( this.backgroundBitmap, this.viewWidth, this.viewHeight, true );
				Log.d( debugName, debugName + " create scaled background" );
			}	
			if ( this.scaleBackgroundBitmap != null )
				canvas.drawBitmap( this.scaleBackgroundBitmap, 0, 0, null ); 
		}
		Paint paint  = new Paint(Paint.LINEAR_TEXT_FLAG);
        paint.setColor( this.textColor );
        paint.setTextSize(20.0F);
		this.CalculateNextTextDrawX();
		canvas.drawText ( strHelloWorld, draw_text_x[0], 20, paint );

		this.CalculateNextDrawX();
		this.CalculateNextDrawY();
		Paint paintBmp = new Paint( Paint.FILTER_BITMAP_FLAG );
		paintBmp.setColor( Color.TRANSPARENT );
		paintBmp.setAlpha( 255 );
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( Color.WHITE, PorterDuff.Mode.SRC_OUT);
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( Color.WHITE , PorterDuff.Mode.DST_OUT);

		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( Color.BLACK , PorterDuff.Mode.DST_OUT);
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( backgroundColor, PorterDuff.Mode.DARKEN);
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( backgroundColor , PorterDuff.Mode.LIGHTEN);
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( Color.TRANSPARENT, PorterDuff.Mode.SCREEN );
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( Color.TRANSPARENT, PorterDuff.Mode.DST_ATOP); // the background on top
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( 0xffff00 , PorterDuff.Mode.LIGHTEN );
		//PorterDuffColorFilter pdcf = new PorterDuffColorFilter( 0xff8a2be2 , PorterDuff.Mode.MULTIPLY );
		//paintBmp.setColorFilter( pdcf );
		//AvoidXfermode axf = new AvoidXfermode(Color.TRANSPARENT, 255 ,AvoidXfermode.Mode.TARGET );   
		//PixelXorXfermode pxx = new PixelXorXfermode ( Color.TRANSPARENT );
		PixelXorXfermode pxx = new PixelXorXfermode ( 0xffffffff );
		paintBmp.setXfermode ( pxx );
		//paintBmp.setStyle( Paint.Style.STROKE ); 
		canvas.drawBitmap(destBitmap[drawPtr], draw_x[0], 20+draw_y[0], paintBmp); 
		//canvas.drawBitmap(destBitmap[drawPtr], draw_x[0], 20+draw_y[0], null ); 
		drawPtr++;
		drawPtr = drawPtr % destBitmap.length;
	}
	@Override
	public void setAdjustViewBounds(boolean adjustViewBounds) {
		mAdjustViewBounds = adjustViewBounds;
		if (adjustViewBounds) {
			setScaleType(ScaleType.FIT_CENTER);
		}
	}

	@Override 
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) 
	{
		int w;
        int h;
        
        float desiredAspect = 0.0f;
        
        boolean resizeWidth = false;
        
        boolean resizeHeight = false;
        
        if ( this.destBitmap == null ) {
            // If no drawable, its intrinsic size is 0.
            w = h = 0;
        } else {

			findMaxSpriteDescription ( this._sd, this._maxWidthSd, this._maxHeightSd );
            w = this._maxWidthSd[0].getWidth();
            h = this._maxHeightSd[0].getHeight() + (this._maxHeightSd[0].getHeight()/4) + bottomPadding ;
			
            if (w <= 0) w = 1;
            if (h <= 0) h = 1;
            
            // We are supposed to adjust view bounds to match the aspect
            // ratio of our drawable. See if that is possible.
            if (mAdjustViewBounds) {
                
                int widthSpecMode = MeasureSpec.getMode(widthMeasureSpec);
                int heightSpecMode = MeasureSpec.getMode(heightMeasureSpec);
                
                resizeWidth = widthSpecMode != MeasureSpec.EXACTLY;
                resizeHeight = heightSpecMode != MeasureSpec.EXACTLY;
                
                desiredAspect = (float)w/(float)h;
            }
        }

		int widthSize = 0;
		int heightSize = 0;
        if (resizeWidth || resizeHeight) {

            // Get the max possible width given our constraints
            widthSize = resolveAdjustedSize(w, w, widthMeasureSpec);
            
            // Get the max possible height given our constraints
            heightSize = resolveAdjustedSize(h, h, heightMeasureSpec);
            
            if (desiredAspect != 0.0f) {
                // See what our actual aspect ratio is
                float actualAspect = (float)(widthSize) /(heightSize);
                
                if (Math.abs(actualAspect - desiredAspect) > 0.0000001) {
                    
                    boolean done = false;
                    
                    // Try adjusting width to be proportional to height
                    if (resizeWidth) {
                        int newWidth = (int)(desiredAspect * heightSize);
						if (newWidth <= widthSize) {
							widthSize = newWidth;
							done = true;
						} 
					}

					// Try adjusting height to be proportional to width
					if (!done && resizeHeight) {
						int newHeight = (int)(widthSize / desiredAspect);
						if (newHeight <= heightSize) {
							heightSize = newHeight;
						} 
					}
				}
			}
		} else {

			w = Math.max(w, getSuggestedMinimumWidth());
			h = Math.max(h, getSuggestedMinimumHeight());

			widthSize = resolveSize(w, widthMeasureSpec);
			heightSize = resolveSize(h, heightMeasureSpec);
		}
		Log.d( this.debugName , "widthSize = "+ widthSize  );
		Log.d( this.debugName , "heightSize= "+ heightSize);
		this.setMeasuredDimension(widthSize,heightSize);
		this.viewWidth = widthSize;
		this.viewHeight = heightSize;
	}
	private int resolveAdjustedSize(int desiredSize, int maxSize,
                                   int measureSpec) {
        int result = desiredSize;
        int specMode = MeasureSpec.getMode(measureSpec);
        int specSize =  MeasureSpec.getSize(measureSpec);
        switch (specMode) {
            case MeasureSpec.UNSPECIFIED:
                /* Parent says we can be as big as we want. Just don't be larger
                   than max size imposed on ourselves.
                */
                result = Math.min(desiredSize, maxSize);
                break;
            case MeasureSpec.AT_MOST:
                // Parent says we can be as big as we want, up to specSize. 
                // Don't be larger than specSize, and don't be larger than 
                // the max size imposed on ourselves.
                result = Math.min(Math.min(desiredSize, specSize), maxSize);
                break;
            case MeasureSpec.EXACTLY:
                // No choice. Do what we are told.
                result = specSize;
                break;
        }
        return result;
    }
	//--------------------------------------------------------------------------------------------------
	// setter
	public void SetDisplayStr( String str ) { this.strHelloWorld = str; }
	public void SetBackground( int c )  { this.backgroundColor = c; }
	public void SetTextColor ( int c ) 	{ this.textColor = c; }
	public void SetBackgroundBitmap ( int resId ) 
	{
		if ( LocalContext == null ) return;
		this.backgroundBitmap = BitmapFactory.decodeResource( LocalContext.getResources(), resId );
	}
}
