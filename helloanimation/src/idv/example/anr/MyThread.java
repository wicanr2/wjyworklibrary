package idv.example.anr;

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

class MyRunner implements Runnable 
{
	String logName = "MyThread";
	
	MyFirstActivity.MyHandler myHandler = null;	
	long defaultSleepInterval = 1000;
	public MyRunner(MyFirstActivity.MyHandler mh )
	{
		myHandler = mh;
	}
	//-------------------------------------------
	// setter
	public void SetSleepInterval(long m)
	{
		this.defaultSleepInterval = m; 
	}
	//-------------------------------------------
	// run
	public void run(){
		Log.d( logName, logName+".run() enter" );
		while ( true )
		{
			if ( Thread.currentThread().isInterrupted() ) 
				break;
			try {   
				Thread.sleep( defaultSleepInterval ); 
			} catch (InterruptedException e) {   
				Thread.currentThread().interrupt();   
			}   

			if ( myHandler == null ) continue;

			Message m= new Message();
			m.what = MyFirstActivity.MyHandler.MSG_RedrawTheImageView01  ;
			myHandler.sendMessage( m );
		}
		Log.d( logName, logName+".run() leave" );
	}
}
