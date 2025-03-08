/******************************************************************************
Second largest using sliding window

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
	    int a[] = {2,9,10,6,13,7};
	    int l = -1, s = -1;
	    for(int i =0;i<a.length;i++) {
            System.out.println(l + " " + s);
	        if(a[i] > l) {
	            s = l;
	            l = a[i];
	            continue;
	        }
	    }
	   System.out.println(s);
	}
}