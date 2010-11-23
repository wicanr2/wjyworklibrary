package idv.example.anr.utils;

public class SpriteLocation {
	private int x = 0;
	private int y = 0;

	public SpriteLocation( int x, int y )
	{
		this.setX( x );
		this.setY( y );
	}
	//-----------------------
	// setter
	public void setX( int v ) { x = v; }
	public void setY( int v ) { y = v; }
	//-----------------------
	// getter
	public int getX() { return x; }
	public int getY() { return y; }

}
