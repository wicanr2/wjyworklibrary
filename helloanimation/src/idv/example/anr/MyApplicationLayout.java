package idv.example.anr;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.LinearLayout;
import android.widget.ImageView;
import android.view.View;
import android.content.Context;
/* 
 * the MyApplicationLayout
 * */
class MyApplicationLayout extends Activity {
	protected TextView textView1 = null;
	protected TextView textView2 = null;
	protected LinearLayout linearLayout = null;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
		this.InitObjects();
    }
	protected int InitObjects() {
		if ( textView1 == null )
			textView1 = new TextView(this);

		if ( textView2 == null )
			textView2 = new TextView(this);

		if ( linearLayout == null )
			linearLayout = new LinearLayout(this);
		// set the linear layout to horizontal
		//linearLayout.setOrientation( LinearLayout.HORIZONTAL );
		linearLayout.setOrientation( LinearLayout.VERTICAL );

		textView1.setText(
				textView1+"\nHello Android, this my first console building apk");
		textView2.setText(
				textView2+"\nHello Android, this my first console building apk");
		//linearLayout.addView( textView1 ); 
		//linearLayout.addView( textView2 ); 
		return 0;
	} // InitObjectEnd
	protected int AddShowView( android.view.View v )
	{
		if ( linearLayout != null ) { 
			linearLayout.addView ( v ) ;	
			return 0;
		}
		return -1;
	}
	protected int FinalRendering() 
	{
		if ( linearLayout != null ) { this.setContentView( linearLayout ); return 0; }
		return -1;	
	}
};
