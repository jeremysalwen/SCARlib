package edu.js.SCARlib;

import java.awt.AWTException;
import java.awt.Point;
import java.awt.Robot;
import java.io.File;

public class SCARLib {
	public static void main(String[] args) {

	}

	long Xdisplayconnection;
	static {
		System.setProperty("java.library.path", System
				.getProperty("java.library.path")
				+ File.pathSeparatorChar + ".");
		System.loadLibrary("SCARLib");
	}

	public SCARLib() {
		this.Xdisplayconnection = XOpenDisplay();
	}

	@Override
	protected void finalize() throws Throwable {
		try {
			XCloseDisplay(Xdisplayconnection);
		} finally {
			super.finalize();
		}
	}

	native long XOpenDisplay(String name);

	native long XOpenDisplay();

	public long UserFindWindow() {
		return UserFindWindow(Xdisplayconnection);
	}

	native long UserFindWindow(long Xconnection);

	native void XCloseDisplay(long connection);

	public Point getWindowLocation(long window) {
		return getWindowLocation(Xdisplayconnection, window);
	}

	native Point getWindowLocation(long connection, long window);

	public long getWindowByName(String name) {
		return getWindowByName(Xdisplayconnection, name);
	}

	native long getWindowByName(long connection, String name);

	public long getRootWindow() {
		return getRootWindow(Xdisplayconnection);
	}

	native long getRootWindow(long connection);

	public void ActivateWindow(long window) {
		ActivateWindow(Xdisplayconnection, window);
	}

	native void ActivateWindow(long connection, long window);

	public Point GetWindowDimensions(long window) {
		return getWindowLocation(Xdisplayconnection, window);
	}

	native Point GetWindowDimensions(long connection, long window);

	public long getWindowByNamePart(String name, boolean casematters) {
		return getWindowByNamePart(Xdisplayconnection, casematters ? name
				: name.toLowerCase(), casematters);
	}

	native long getWindowByNamePart(long connection, String name,
			boolean casematters);

	public long GetWindowBySize(int width, int height) {
		return GetWindowBySize(Xdisplayconnection, width, height);
	}

	public native long GetWindowBySize(long connection, int width, int height);
}
