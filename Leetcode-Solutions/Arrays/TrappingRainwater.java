public class TrappingRainwater {
    public static int trap(int[] a) {
        int res=0;
        int n=a.length;
        int l[]=new int[a.length];
        int r[]=new int[a.length];
        l[0]=a[0];
        for(int i=1;i<n;i++){
            l[i]=Math.max(a[i],l[i-1]);
        }
        r[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=Math.max(a[i],r[i+1]);
        }
        for(int i=1;i<a.length-1;i++){
            res+=Math.min(l[i],r[i])-a[i];
        }
        return res;
    }

    public static void main(String[] args) {
int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
int res=trap(a);
        System.out.println(res);
    }
}
