interns at amazons were asked to review company's stock over a period of time ,given the stock prices of n month the net price change for ith month is defined asthe 
  absolute difference between 
  
  private int solve(int[] stock){
    long suf = Arrays.stream(stock).asLongStream().sum(), pre = 0;
    int ans = 0, min = Integer.MAX_VALUE;
    for (int i = 0; i < stock.length-1; i++){
        pre += stock[i];
        suf -= stock[i];
        int diff = Math.abs(pre/(i+1)-suf/(stock.length-i-1));
        if (diff<min){
            ans=i+1;
            min=diff;
        }
    }
    return ans;
}
