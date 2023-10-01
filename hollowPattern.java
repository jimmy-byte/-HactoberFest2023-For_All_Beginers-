class Pattern{
  public static void main(String[] args){
    int n=21;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if((i+j<=(n-1)/2 && i+j>=0) || (i-j>=(n-1)/2 && i-j<=(n-1)) || (j-i>=(n-1)/2 && j-i<=(n-1)) || (i+j>=(n-1)+(n-1)/2 && i+j<=2*(n-1))) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
  }
}
//Run this code -----------------------------------------Pattern is exiciting--------------------------------
