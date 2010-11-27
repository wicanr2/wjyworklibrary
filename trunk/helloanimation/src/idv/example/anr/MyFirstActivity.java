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

import android.graphics.Matrix;
import android.widget.*;
import android.widget.Gallery.LayoutParams;
import android.widget.ImageView.ScaleType; 
import android.util.Log; 

import android.os.Bundle;  
import android.os.Handler;  
import android.os.Message;

public class MyFirstActivity extends MyApplicationLayout 
{
	private MyImageView imageView01 = null;	
	private MyImageView imageView02 = null;	
	private MyImageView imageView03 = null;	

	private int testjpg_resId = R.drawable.testjpg;
	private int mario_sprite_redId = R.drawable.mario_sprite;
	private int mario_bg = R.drawable.mario_bg;
	private int pacman   = R.drawable.pacman;
	//-----------------------------------------------------------
	// Activtiy Action
	/* Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
		DoLog ("onCreate");
        super.onCreate(savedInstanceState);

		imageView02 = new MyImageView( this );
		imageView02.setAdjustViewBounds(true);
		this.InitSpriteToMyImageView02( imageView02 );
		this.AddShowView ( imageView02 );

		/*imageView01 = new MyImageView( this );
		imageView01.setAdjustViewBounds(true);
		this.InitSpriteToMyImageView( imageView01 );
		this.AddShowView ( imageView01 );*/

		imageView03 = new MyImageView( this );
		imageView03.setAdjustViewBounds(true);
		this.InitSpriteToMyImageView03( imageView03 );
		this.AddShowView ( imageView03 );

		this.FinalRendering();
		this.CreateThread();
    }

    @Override
	protected void onPause ()
	{
		DoLog ("onPause");
		super.onPause();
		this.DestroyThread();
	}

    @Override
	protected void onResume ()	
	{
		DoLog ("onResume");
		super.onResume();
		this.CreateThread();
	}
	//-----------------------------------------------------------------------
	// initImageView01
	private void InitSpriteToMyImageView(MyImageView miv) 
	{
		if ( miv == null ) return;
		SpriteDescription[] sd = new SpriteDescription[6];
		sd[0] = new SpriteDescription(270,144);
		sd[1] = new SpriteDescription(270,144);
		sd[2] = new SpriteDescription(270,144);
		sd[3] = new SpriteDescription(270,144);
		sd[4] = new SpriteDescription(270,144);
		sd[5] = new SpriteDescription(270,144);
		SpriteLocation [] sl = new SpriteLocation[6];
		sl[0] = new SpriteLocation(10 ,79);
		sl[1] = new SpriteLocation(287,79);
		sl[2] = new SpriteLocation(565,79);
		sl[3] = new SpriteLocation(843,79);
		sl[4] = new SpriteLocation(1121,79);
		sl[5] = new SpriteLocation(1339,79);

		miv.SetDisplayStr ( "Adult Henta World!!!" );
		miv.AddBitmap ( testjpg_resId, sl, sd );
	}	

	private void InitSpriteToMyImageView02(MyImageView miv) 
	{
		if ( miv == null ) return;
		SpriteDescription[] sd = new SpriteDescription[4];
		sd[0] = new SpriteDescription(26,44);
		sd[1] = new SpriteDescription(26,44);
		sd[2] = new SpriteDescription(26,44);
		sd[3] = new SpriteDescription(26,44);

		SpriteLocation [] sl = new SpriteLocation[4];
		sl[0] = new SpriteLocation(12 ,8);
		sl[1] = new SpriteLocation(42, 8);
		sl[2] = new SpriteLocation(72, 8);
		sl[3] = new SpriteLocation(102,8);
		miv.SetBackground( Color.WHITE );
		miv.SetTextColor ( Color.BLACK );
		miv.SetDisplayStr ( "Mario World!!!" );
		miv.SetBackgroundBitmap( this.mario_bg );
		miv.AddBitmap ( mario_sprite_redId, sl, sd );
	}	
	private void InitSpriteToMyImageView03(MyImageView miv) 
	{
		if ( miv == null ) return;
		SpriteDescription[] sd = new SpriteDescription[1];
		sd[0] = new SpriteDescription(12,12);
		SpriteLocation [] sl = new SpriteLocation[1];
		sl[0] = new SpriteLocation(4,4);

		miv.SetBackground( Color.WHITE );
		miv.SetTextColor ( Color.BLACK );
		miv.SetDisplayStr ( "Eather World!!!" );
		miv.SetBackgroundBitmap( this.mario_bg );
		miv.AddBitmap ( pacman, sl, sd );
	}	
	//-----------------------------------------------------------------------
	// handler
	public class MyHandler extends Handler
	{
		String logName = "MyHandler";
		public static final int MSG_RedrawTheImageView01 = 0x1234;
		public void handleMessage(Message msg) {  
			//Log.d ( logName, "Message = " +  msg.what ) ;
			switch ( msg.what )
			{
				case MSG_RedrawTheImageView01:
					if ( MyFirstActivity.this.imageView01 != null )
					{
						MyFirstActivity.this.imageView01.invalidate();
					}
					if ( MyFirstActivity.this.imageView02 != null )
					{
						MyFirstActivity.this.imageView02.invalidate();
					}
					if ( MyFirstActivity.this.imageView03 != null )
					{
						MyFirstActivity.this.imageView03.invalidate();
					}
					break;	
			}
            super.handleMessage(msg);  
        } 
	}
	//---------------------------------------------------------------
	// log
	private static String logName = "MyFirstActivity";
	private static void DoLog(String msg){
		Log.d( logName, logName + " " + msg );
	}
	//---------------------------------------------------------------
	// thread maintain functions
	Thread th = null ;
	synchronized private void CreateThread()
	{
		if ( th != null ) return ;
		MyHandler mh = new MyHandler();
		MyRunner mr = new MyRunner(mh);
		mr.SetSleepInterval(66);
		th = new Thread( mr ); 
		th.start();
	}	
	synchronized private void DestroyThread()
	{
		if ( th != null ) {
			th.interrupt();
			try {
				th.join();
			} catch (InterruptedException e) {   
				th = null;
				return ;
			}
			th = null;
			return ;
		}
	}	
}
