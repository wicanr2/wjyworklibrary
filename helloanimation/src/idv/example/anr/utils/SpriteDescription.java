package idv.example.anr.utils;

public class SpriteDescription
{
	int width  = 0;
	int height = 0;
	public SpriteDescription( int w, int h )
	{
		this.setWidth( w );
		this.setHeight( h );
	}
	//-----------------------
	// setter
	public void setWidth (int v) { width = v;  }
	public void setHeight(int v) { height = v; }
	//-----------------------
	// getter
	public int getWidth () { return width;  }
	public int getHeight() { return height; }
}
