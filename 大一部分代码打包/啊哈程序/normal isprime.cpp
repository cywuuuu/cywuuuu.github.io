bool prime(int x){//判断x是不是质数，是返回true，不是返回false 

    if(x<=1) return false; 

    for(int i=2;i*i<=x;i++)//用乘法避免根号的精度误差

    { 

        if(x%i==0) return false;

    }

    return true;

}
