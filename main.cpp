#include <hls_math.h>
#include <ap_int.h>
#include "ldpcDec.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	int err_cnt = 0;
	ap_int<6> llr_ch[8000];
	ap_int<6> llr_src[6400];

	bool gc_result[6400];
	bool rtl_result[6400];

	FILE *fp1,*fp2,*fp3,*fp4;
	fp1 = fopen("D:\\PhD_Study\\JSCC_LDPC\\jscc_6bit_min_sum_hdl\\data\\Source_LLR.txt", "r");
	fp2 = fopen("D:\\PhD_Study\\JSCC_LDPC\\jscc_6bit_min_sum_hdl\\data\\Channel_LLR.txt", "r");
	fp3 = fopen("D:\\PhD_Study\\JSCC_LDPC\\jscc_6bit_min_sum_hdl\\data\\decoded_sourceBits.txt", "r");

	for(int i=0;i<6400;i++){
		int d;
		fscanf(fp1, "%d", &d);
		llr_src[i] = d;
	}
    fclose(fp1);
	for(int i=0;i<8000;i++){
		int d;
		fscanf(fp2, "%d", &d);
		llr_ch[i] = d;
	}
    fclose(fp2);
	for(int i=0;i<6400;i++){
		int r;
		fscanf(fp3, "%d", &r);
		gc_result[i] = r==1;
	}
    fclose(fp3);
	ldpcDec(llr_ch, llr_src, rtl_result);

	fp4 = fopen("rtl_result.txt","w");

	for(int i=0;i<6400;i++){
		if(rtl_result[i]!=gc_result[i])
			err_cnt++;
		fprintf(fp4,"%d\n",rtl_result[i]);
	}
	fclose(fp4);
	printf("Error cnt : %d\n",err_cnt);
	return err_cnt;
}
