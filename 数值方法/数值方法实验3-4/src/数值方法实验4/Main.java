package 数值方法实验4;
/**
 * 牛顿插值法
 * @author 75616
 *
 */
public class Main {
	
	/**
	 * values为两行n列的数组
	 * values[0]行为x值，values[1]行为y值；
	 */
	double [][]values;
	/**
	 * F保存牛顿迭代法中的差商
	 */
	double [][]F;
	/**
	 * arr为两行n列的数组
	 * arr[0]行为x，arr[1]行为f(x)的值
	 */
	public Main(double [][]arr ) {
		this.values=arr;
		F=new double[arr[1].length-1][arr[1].length-1];
		sovleF();
	}
	//求解差商
	private void sovleF() {
		for (int i = 0; i < F.length; i++) {
			for (int j = 0; j < F[i].length-i; j++) {
				if (i==0) {
					F[i][j]=(values[1][j]-values[1][j+1])/(values[0][j]-values[0][j+1]);
					continue;
				}
				F[i][j]=(F[i-1][j]-F[i-1][j+1])/(values[0][j]-values[0][j+i+1]);
			}
		}
	}
	/**
	 *  x为自变量
	 * 返回值为与x对应的解
	 */
	public double getResult(double x) {
		double result=values[1][0];
		for (int i = 0; i < F.length; i++) {
			result+=F[i][i]*getPol(x, i);
		}
		return result;
	}
	//(x-x(0))(x-x(1))...(x-x(k+1))
	public double getPol(double x,int k) {
		double result=1;
		for(int i=0;i<=k;i++)
			result*=(x-values[0][i]);
		return result;
	}
	public static void main(String[] args) {
		double[][]arr={
				{0.4, 0.55, 0.65, 0.80, 0.90, 1.05},
				{0.41075, 0.57815, 0.69675, 0.88811, 1.02652, 1.25386}
		};
		Main main=new Main(arr);
		
		System.err.println("当x=0.596时，由牛顿插值法可得N(0.596)="+main.getResult(0.596));
	}

}
