#include <stdio.h>

int soto(int *start,int *end);
int main(void)
{
	int array[20] = {0};
	int i = 0;
	int n = 0;
	int ret;

	printf("insert[%d]",i);
	ret = scanf("%d",array);
	while(ret != EOF)
	{
		i++;
		printf("insert[%d]",i);
		ret = scanf("%d",array+i);

	}
	if(i ==0 )
	{
		i = 1;
	}
	i = i-1;
	#ifdef DEBUG
		printf("i is %d\n",i);
	#endif
	soto(array,array+i);

	while(i >= 0)
	{
		printf("����[%d]:%d\n",n,array[n]);
		n++;
		i--;
	}
	
	return 0;
}
int soto(int *start,int *end)
{
	int len = 0;
	int stlen = 0;
	int edlen = 0;
	int pivot = *start;
	int w;

	/*�z��̒��������߂Ă��܂�*/

	while(start+len != end)
	{
		len++;	
	}
	#ifdef DEBUG
		printf("array�̒�����-->0�`%d\n",len);
	#endif
	
	/*�\�[�g�̏������e�ł�*/

	w = *start;
	while(start+stlen != end-edlen)
	{
		if(*(end-edlen) < pivot )
		{
			*(start+stlen) = *(end - edlen);
			*(end - edlen) = w;
			stlen++;
		}
		else
		{
			edlen++;
		}
		while(*(start+stlen) < pivot)
		{
			stlen++;
		}
		w = *(start+stlen);
	}
	/*�o�O�̔�����h���܂�*/
	if(stlen == 0 && edlen != 0)
	{
		stlen++;
		edlen--;
	}
	/*�\�[�g���J��Ԃ��܂�*/
	#ifdef DEBUG
		printf("stlen is %d\nedlen is %d\n",stlen,edlen);
	#endif
	if(!(stlen == 0 && edlen==0))
	{
		soto(start,start+(stlen-1));
		soto(start+stlen,start+len);
	}
	

}