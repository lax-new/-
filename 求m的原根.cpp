#include<stdio.h>

int size;

bool juge_ifprime(int m){		//�ж������m�Ƿ�Ϊ������ 
	for(int i=2;i<=m/2;i++){
		if(m%i==0)
			return false;		//����������Ϊ1����false 
	}
	return true;				//���򷵻�true
}

void count_EulerNot(int m,int* array){	//���������m�������ֽ�ʽ 
	int temp1=m;
	if(int(juge_ifprime(m))==1){		//��������mΪ�������������һ֮������ 
		temp1-=1;
	}
	int number=0;						//���������������ָ�� 
	int temp=temp1; 
	while(temp!=1){
		for(int i=2;i<=temp;i++){
			if(int(juge_ifprime(i))==1&&temp%i==0&&i!=m)
			{
				array[number++]=i;
				temp/=i;				//�ҵ�һ��������(��i=m)֮��temp����i�ı�temp��ֵʹ����������ѭ��
			}
		}						 
	}
} 

int count_Euler(int *array,int m){
	int Eulernumber;
	if(int(juge_ifprime(m))==1){
		return m-1;
	}
	else{
	for(int i=0;i<size;i++){
		if(array[i]!=-1){
			Eulernumber=m/array[i]*(array[i]-1);
		}
	}
	return Eulernumber;}
}

bool juge_HUSU(int a,int m){	//�ж������Ƿ���,�����ǵ����Լ���Ƿ�Ϊ1 
	for(int i=2;i<=a;i++){
		if(a%i==0&&m%i==0){
			return false;
		}
	}
	return true;
} 

void count_mHUSU(int *brrby,int m){	//����m���ص���������ĺ���,�������Сԭ��(�ڶ��ε��õ�ʱ������Ǻ�ŷ���������ص�����)
	int number=0;					//�������洢brrby�����int��ָ�� 
	int temp=m;
	for(int i=1;i<temp;i++){
		if(juge_HUSU(i,temp)!=0&&number<size){
			brrby[number++]=i;
		}
	}
} 

bool juge_MinPrimitiveRoot(int temp,int brrby,int m){	//��brrby������ѡһ����m���ص�����������temp�η��Ƿ�mod m��m-1�ж����Ƿ�Ϊ��Сԭ�� 
	int number=1;			//����һ��number���ڴ�Ŵ����temp��ֵ 
	for(int i=0;i<temp;i++){
		number*=brrby;
		number=number%m;
		if(number==1)
		return false; 
	}
	if(number==m-1)
	return true;
	else
	return false;
}

int count_MinPrimitiveRoot(int m,int *array,int *brrby,int Eulernumber){//������Сԭ��,����arrayΪ����������,brrbyΪ��ŷ���������ص��������� 
	int temp;
	for(int i=0;i<size;i++){
		if(array[i]!=-1){
			for(int j=0;j<size;j++){
			temp=Eulernumber/array[i];	//ŷ���������������ĳ���q
			if(int(juge_MinPrimitiveRoot(temp,brrby[j],m))==0){
				
			} 
			if(int(juge_MinPrimitiveRoot(temp,brrby[j],m))==1&&brrby[j]!=-1){
				return brrby[j];
			}
			}
		}
	}
	return -1;
}

void Sort(int* array){		//��array����Ӵ�С���� 
	int temp;				//��ʱ�������ڽ�������Ԫ�� 
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]!=-1&&array[j]!=-1&&array[i]>array[j]){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
} 

void Delete_same(int *array){		//���������������ͬԪ���޳� 
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]==array[j]){
				array[j]=-1;
			}
		}
	}
}

void ALL_primeroot(int minprimerroot,int *drrdy,int *crrcy,int m){	//����Ĳ���Ϊ��Сԭ������m���ص�����drrdy������������е�ԭ��������crrcy������ 
	int temp=1;
	for(int i=0;i<size;i++){
		if(drrdy[i]!=-1){
			for(int j=0;j<drrdy[i];j++){
				temp*=minprimerroot;
				temp%=m;
			}
			crrcy[i]=temp;
			temp=1;
		}
	}
} 

int main(){
	int m;
	printf("������Ҫ�������");
	scanf("%d",&m);					//������Ҫ���ԭ����m 
	size=m/2;
	int array[size];					//���ڴ��������������array 
	int brrby[size];					//���ڴ����m���ص����ֵ����� 
	int crrcy[size];					//���ڴ��m������ԭ�������� 
	int drrdy[size];
	for(int i=0;i<size;i++){			//��������ȫ�����ݳ�ʼ��Ϊ-1,�������� 
		array[i]=-1;
		brrby[i]=-1;
		crrcy[i]=-1; 
		drrdy[i]=-1;
	}
	count_EulerNot(m,array);		//��ʱarray�����ﲻΪ-1�ľ���m���������ֽ� 
	Delete_same(array);				//�޳�array��������ͬ����
	int Eulernumber=count_Euler(array,m);	//����m��ŷ������ 
	count_EulerNot(Eulernumber,array);		//��ʱarray�����ﲻΪ-1�ľ���m���������ֽ� 
	Delete_same(array);				//�޳�array��������ͬ����
	Sort(array);					//������array���дӴ�С������ 
	count_mHUSU(brrby,m);			//����m���ص�Ԫ�أ�����brrby��
	int minprimerroot=count_MinPrimitiveRoot(m,array,brrby,Eulernumber);//����Сԭ�� 
	if(minprimerroot==-1){
		printf("����û��ԭ����\n");
		return 0;
	}
	printf("��Сԭ��Ϊ��%d\n",minprimerroot);	//��ӡ��Сԭ��
	count_mHUSU(drrdy,Eulernumber);			//����Eulernumber���ص�Ԫ�أ�����brrby��
	ALL_primeroot(minprimerroot,drrdy,crrcy,m);	//֪����Сԭ��֮����б��������������ԭ�� 
	Sort(crrcy);					//������crrcy���дӴ�С������ 
	int primernumber=0;				//�������ڼ���ԭ�������ı��� 
	for(int i=0;i<size;i++){		//��brrby������б������ҳ��ж��ٸ�ԭ�� 
		if(drrdy[i]!=-1){
			primernumber++;
		}
	}
	printf("ŷ��������ֵΪ��%d\n",Eulernumber);	//���ŷ��������ֵ 
	printf("һ����%d��ԭ����\nԭ���Ӵ�С����Ϊ��\n",primernumber);//���ԭ���ĸ��� 
	for(int i=0;i<size;i++){		//��ӡ����crrcy������� 
		if(crrcy[i]!=-1){
			printf("%d\t",crrcy[i]);
		}
	}
	printf("\n");
}
