bool prime(int x){//�ж�x�ǲ����������Ƿ���true�����Ƿ���false 

    if(x<=1) return false; 

    for(int i=2;i*i<=x;i++)//�ó˷�������ŵľ������

    { 

        if(x%i==0) return false;

    }

    return true;

}
