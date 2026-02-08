#include <hls_math.h>
#include <ap_int.h>
#include "ldpcDec.h"

void readSrcData(ap_int<6> llr_src[6400],ap_int<6> minfo_src[285][256],ap_int<6> blockllr_src[40][256], ap_int<6> llr_src_2_ch[3200]){

    for(int i=0;i<40;i++){		//Ns/BL
        for(int j=0;j<BL;j++){         //BL=160
//#pragma HLS PIPELINE
        	ap_int<6> s= llr_src[i*BL+j];
        	blockllr_src[i][j] = s;
//        	for(int k=0;k<285;k++){    //No. of non-zero sub-matrices is 285
//#pragma HLS UNROLL factor=285
//                if(k>=sel_src[i]&&k<sel_src[i+1]){
//                	minfo_src[k][j] = s;
//                }
//        	}
        }
    }

    for(int i=0;i<285;i++){
    	for(int j=0;j<256;j++){
    		minfo_src[i][j] = 0;
    	}
    }

    for(int i=0;i<3200;i++){
//#pragma HLS UNROLL factor=3200
        llr_src_2_ch[i] = 0;
    }
}

void readChData(ap_int<6> llr_ch[8000],ap_int<6> minfo_ch[130][256],ap_int<6> blockllr_ch[50][256],ap_int<6> llr_ch_2_src[3200]){
    for(int i=0;i<50;i++){		//Nc/BL
        for(int j=0;j<BL;j++){         //BL=160
//#pragma HLS PIPELINE
            ap_int<6> s= llr_ch[i*BL+j];
            blockllr_ch[i][j] = s;
//            for(int k=0;k<129;k++){    //No. of non-zero sub-matrices is 128
//#pragma HLS UNROLL factor=128
//                if(k>=sel_ch[i]&&k<sel_ch[i+1]){
//                	minfo_ch[k][j] = s;
//                }
//            }
        }
    }

    for(int i=0;i<130;i++){
    	for(int j=0;j<256;j++){
    		minfo_ch[i][j] = 0;
    	}
    }

    for(int i=0;i<3200;i++){
//#pragma HLS UNROLL factor=3200
        llr_ch_2_src[i] = llr_ch[4800+i];
    }
}

void updateSrcMinfo(ap_int<6> minfo_src[285][256], ap_int<6> blockllr_src[40][256], ap_int<6> llr_src_2_ch[3200], ap_int<6> llr_ch_2_src[3200], bool blockdout_src[40][256]){

//#pragma HLS ARRAY_PARTITION variable=minfo_src complete dim=1
//#pragma HLS ARRAY_PARTITION variable=blockllr_src complete dim=1
//#pragma HLS ARRAY_PARTITION variable=blockdout_src complete dim=1

	//V2C message update, column update
	    colUpdate15(blockdout_src[0] ,blockllr_src[0] ,minfo_src[0]  ,minfo_src[1]  ,minfo_src[2]  ,minfo_src[3]  ,minfo_src[4]  ,minfo_src[5]  ,minfo_src[6]  ,minfo_src[7]  ,minfo_src[8]  ,minfo_src[9]  ,minfo_src[10] ,minfo_src[11] ,minfo_src[12] ,minfo_src[13] ,minfo_src[14]);
	    colUpdate15(blockdout_src[1] ,blockllr_src[1] ,minfo_src[15] ,minfo_src[16] ,minfo_src[17] ,minfo_src[18] ,minfo_src[19] ,minfo_src[20] ,minfo_src[21] ,minfo_src[22] ,minfo_src[23] ,minfo_src[24] ,minfo_src[25] ,minfo_src[26] ,minfo_src[27] ,minfo_src[28] ,minfo_src[29]);
	    colUpdate15(blockdout_src[2] ,blockllr_src[2] ,minfo_src[30] ,minfo_src[31] ,minfo_src[32] ,minfo_src[33] ,minfo_src[34] ,minfo_src[35] ,minfo_src[36] ,minfo_src[37] ,minfo_src[38] ,minfo_src[39] ,minfo_src[40] ,minfo_src[41] ,minfo_src[42] ,minfo_src[43] ,minfo_src[44]);
	    colUpdate15(blockdout_src[3] ,blockllr_src[3] ,minfo_src[45] ,minfo_src[46] ,minfo_src[47] ,minfo_src[48] ,minfo_src[49] ,minfo_src[50] ,minfo_src[51] ,minfo_src[52] ,minfo_src[53] ,minfo_src[54] ,minfo_src[55] ,minfo_src[56] ,minfo_src[57] ,minfo_src[58] ,minfo_src[59]);
	    colUpdate15(blockdout_src[4] ,blockllr_src[4] ,minfo_src[60] ,minfo_src[61] ,minfo_src[62] ,minfo_src[63] ,minfo_src[64] ,minfo_src[65] ,minfo_src[66] ,minfo_src[67] ,minfo_src[68] ,minfo_src[69] ,minfo_src[70] ,minfo_src[71] ,minfo_src[72] ,minfo_src[73] ,minfo_src[74]);
	    colUpdate11(blockdout_src[5] ,blockllr_src[5] ,minfo_src[75] ,minfo_src[76] ,minfo_src[77] ,minfo_src[78] ,minfo_src[79] ,minfo_src[80] ,minfo_src[81] ,minfo_src[82] ,minfo_src[83] ,minfo_src[84] ,minfo_src[85] );
	    colUpdate11(blockdout_src[6] ,blockllr_src[6] ,minfo_src[86] ,minfo_src[87] ,minfo_src[88] ,minfo_src[89] ,minfo_src[90] ,minfo_src[91] ,minfo_src[92] ,minfo_src[93] ,minfo_src[94] ,minfo_src[95] ,minfo_src[96] );
	    colUpdate11(blockdout_src[7] ,blockllr_src[7] ,minfo_src[97] ,minfo_src[98] ,minfo_src[99] ,minfo_src[100],minfo_src[101],minfo_src[102],minfo_src[103],minfo_src[104],minfo_src[105],minfo_src[106],minfo_src[107]);
	    colUpdate11(blockdout_src[8] ,blockllr_src[8] ,minfo_src[108],minfo_src[109],minfo_src[110],minfo_src[111],minfo_src[112],minfo_src[113],minfo_src[114],minfo_src[115],minfo_src[116],minfo_src[117],minfo_src[118]);
	    colUpdate11(blockdout_src[9] ,blockllr_src[9] ,minfo_src[119],minfo_src[120],minfo_src[121],minfo_src[122],minfo_src[123],minfo_src[124],minfo_src[125],minfo_src[126],minfo_src[127],minfo_src[128],minfo_src[129]);
	    colUpdate3 (blockdout_src[10],blockllr_src[10],minfo_src[130],minfo_src[131],minfo_src[132]);
	    colUpdate3 (blockdout_src[11],blockllr_src[11],minfo_src[133],minfo_src[134],minfo_src[135]);
	    colUpdate3 (blockdout_src[12],blockllr_src[12],minfo_src[136],minfo_src[137],minfo_src[138]);
	    colUpdate3 (blockdout_src[13],blockllr_src[13],minfo_src[139],minfo_src[140],minfo_src[141]);
	    colUpdate3 (blockdout_src[14],blockllr_src[14],minfo_src[142],minfo_src[143],minfo_src[144]);
	    colUpdate3 (blockdout_src[15],blockllr_src[15],minfo_src[145],minfo_src[146],minfo_src[147]);
	    colUpdate3 (blockdout_src[16],blockllr_src[16],minfo_src[148],minfo_src[149],minfo_src[150]);
	    colUpdate3 (blockdout_src[17],blockllr_src[17],minfo_src[151],minfo_src[152],minfo_src[153]);
	    colUpdate3 (blockdout_src[18],blockllr_src[18],minfo_src[154],minfo_src[155],minfo_src[156]);
	    colUpdate3 (blockdout_src[19],blockllr_src[19],minfo_src[157],minfo_src[158],minfo_src[159]);
	    colUpdate19(blockdout_src[20],blockllr_src[20],minfo_src[160],minfo_src[161],minfo_src[162],minfo_src[163],minfo_src[164],minfo_src[165],minfo_src[166],minfo_src[167],minfo_src[168],minfo_src[169],minfo_src[170],minfo_src[171],minfo_src[172],minfo_src[173],minfo_src[174],minfo_src[175],minfo_src[176],minfo_src[177],minfo_src[178]);
	    colUpdate19(blockdout_src[21],blockllr_src[21],minfo_src[179],minfo_src[180],minfo_src[181],minfo_src[182],minfo_src[183],minfo_src[184],minfo_src[185],minfo_src[186],minfo_src[187],minfo_src[188],minfo_src[189],minfo_src[190],minfo_src[191],minfo_src[192],minfo_src[193],minfo_src[194],minfo_src[195],minfo_src[196],minfo_src[197]);
	    colUpdate19(blockdout_src[22],blockllr_src[22],minfo_src[198],minfo_src[199],minfo_src[200],minfo_src[201],minfo_src[202],minfo_src[203],minfo_src[204],minfo_src[205],minfo_src[206],minfo_src[207],minfo_src[208],minfo_src[209],minfo_src[210],minfo_src[211],minfo_src[212],minfo_src[213],minfo_src[214],minfo_src[215],minfo_src[216]);
	    colUpdate19(blockdout_src[23],blockllr_src[23],minfo_src[217],minfo_src[218],minfo_src[219],minfo_src[220],minfo_src[221],minfo_src[222],minfo_src[223],minfo_src[224],minfo_src[225],minfo_src[226],minfo_src[227],minfo_src[228],minfo_src[229],minfo_src[230],minfo_src[231],minfo_src[232],minfo_src[233],minfo_src[234],minfo_src[235]);
	    colUpdate19(blockdout_src[24],blockllr_src[24],minfo_src[236],minfo_src[237],minfo_src[238],minfo_src[239],minfo_src[240],minfo_src[241],minfo_src[242],minfo_src[243],minfo_src[244],minfo_src[245],minfo_src[246],minfo_src[247],minfo_src[248],minfo_src[249],minfo_src[250],minfo_src[251],minfo_src[252],minfo_src[253],minfo_src[254]);
	    colUpdate2 (blockdout_src[25],blockllr_src[25],minfo_src[255],minfo_src[256]);
	    colUpdate2 (blockdout_src[26],blockllr_src[26],minfo_src[257],minfo_src[258]);
	    colUpdate2 (blockdout_src[27],blockllr_src[27],minfo_src[259],minfo_src[260]);
	    colUpdate2 (blockdout_src[28],blockllr_src[28],minfo_src[261],minfo_src[262]);
	    colUpdate2 (blockdout_src[29],blockllr_src[29],minfo_src[263],minfo_src[264]);
	    colUpdate2 (blockdout_src[30],blockllr_src[30],minfo_src[265],minfo_src[266]);
	    colUpdate2 (blockdout_src[31],blockllr_src[31],minfo_src[267],minfo_src[268]);
	    colUpdate2 (blockdout_src[32],blockllr_src[32],minfo_src[269],minfo_src[270]);
	    colUpdate2 (blockdout_src[33],blockllr_src[33],minfo_src[271],minfo_src[272]);
	    colUpdate2 (blockdout_src[34],blockllr_src[34],minfo_src[273],minfo_src[274]);
	    colUpdate2 (blockdout_src[35],blockllr_src[35],minfo_src[275],minfo_src[276]);
	    colUpdate2 (blockdout_src[36],blockllr_src[36],minfo_src[277],minfo_src[278]);
	    colUpdate2 (blockdout_src[37],blockllr_src[37],minfo_src[279],minfo_src[280]);
	    colUpdate2 (blockdout_src[38],blockllr_src[38],minfo_src[281],minfo_src[282]);
	    colUpdate2 (blockdout_src[39],blockllr_src[39],minfo_src[283],minfo_src[284]);


	//C2V message update, row update

	    for(int i=0;i<BL;i++){
	////#pragma HLS DEPENDENCE variable=minfo_src inter false
	//#pragma HLS PIPELINE
	        ARRAY16   a[20];
	        ARRAY16_2 b[20];
	        for(int j=0;j<20;j++){
	//#pragma HLS UNROLL factor=2
		        if (j>4) {
			        for(int k=0;k<15;k++){
	//#pragma HLS UNROLL
			            a[j].a[k] = minfo_src[rowPara_src[j][k]][(pidx_src[rowPara_src[j][k]]+i)%BL];
			        }
			        a[j].a[15] = llr_ch_2_src[i+BL*j];  //????
			        b[j] = rowUpdate16(a[j]);
		        }
		        else {      // when j<4 && j==4
			        for(int k=0;k<15;k++){
	//#pragma HLS UNROLL
			            if(k<12)
			            	a[j].a[k] = minfo_src[rowPara_src[j][k]][(pidx_src[rowPara_src[j][k]]+i)%BL];
			            else
			            	a[j].a[k] = 31;
			        }
			        a[j].a[15] = llr_ch_2_src[i+BL*j];  //?????
			        b[j] = rowUpdate16(a[j]);
		        }


	            llr_src_2_ch[i+BL*j] = b[j].i_sc_or_cc; //????

	            if (j>4) {
	                for (int k=0; k<15; k++){
	//#pragma HLS UNROLL
	                    minfo_src[rowPara_src[j][k]][(pidx_src[rowPara_src[j][k]]+i)%BL] = b[j].a[k];
	                }
	            }
	            else {      // when j<4 && j==4
	                for (int k=0; k<12; k++){
	//#pragma HLS UNROLL
	                    minfo_src[rowPara_src[j][k]][(pidx_src[rowPara_src[j][k]]+i)%BL] = b[j].a[k];
	                }
	            }
	        }
	    }

}

void updateChMinfo(ap_int<6> minfo_ch[130][256], ap_int<6> blockllr_ch[50][256], ap_int<6> llr_src_2_ch[3200], ap_int<6> llr_ch_2_src[3200]){

//#pragma HLS ARRAY_PARTITION variable=minfo_ch complete dim=1
//#pragma HLS ARRAY_PARTITION variable=blockllr_ch complete dim=1

    ap_int<6> blockllr_src_2_ch[20][256];
    ap_int<6> blockllr_ch_2_src[20][256];

    for(int p=0;p<20;p++){		//Ns/BL
        for(int q=0;q<BL;q++){         //BL=160
//#pragma HLS PIPELINE
        	ap_int<6> s= llr_src_2_ch[p*BL+q];
	        blockllr_src_2_ch[p][q] = s;
        }
    }

    //I_sc2cc process

    colUpdate_ch (blockllr_ch[0] ,minfo_ch[0] );
    colUpdate_ch (blockllr_ch[1] ,minfo_ch[1] );
    colUpdate_ch (blockllr_ch[2] ,minfo_ch[2] );
    colUpdate_ch (blockllr_ch[3] ,minfo_ch[3] );
    colUpdate_ch (blockllr_ch[4] ,minfo_ch[4] );
    colUpdate_ch (blockllr_ch[5] ,minfo_ch[5] );
    colUpdate_ch (blockllr_ch[6] ,minfo_ch[6] );
    colUpdate_ch (blockllr_ch[7] ,minfo_ch[7] );
    colUpdate_ch (blockllr_ch[8] ,minfo_ch[8] );
    colUpdate_ch (blockllr_ch[9] ,minfo_ch[9] );
    colUpdate2_ch(blockllr_ch[10],minfo_ch[10],minfo_ch[11]);
    colUpdate2_ch(blockllr_ch[11],minfo_ch[12],minfo_ch[13]);
    colUpdate2_ch(blockllr_ch[12],minfo_ch[14],minfo_ch[15]);
    colUpdate2_ch(blockllr_ch[13],minfo_ch[16],minfo_ch[17]);
    colUpdate2_ch(blockllr_ch[14],minfo_ch[18],minfo_ch[19]);
    colUpdate2_ch(blockllr_ch[15],minfo_ch[20],minfo_ch[21]);
    colUpdate2_ch(blockllr_ch[16],minfo_ch[22],minfo_ch[23]);
    colUpdate2_ch(blockllr_ch[17],minfo_ch[24],minfo_ch[25]);
    colUpdate2_ch(blockllr_ch[18],minfo_ch[26],minfo_ch[27]);
    colUpdate2_ch(blockllr_ch[19],minfo_ch[28],minfo_ch[29]);
    colUpdate4_ch(blockllr_ch[20],minfo_ch[30],minfo_ch[31],minfo_ch[32],minfo_ch[33]);
    colUpdate4_ch(blockllr_ch[21],minfo_ch[34],minfo_ch[35],minfo_ch[36],minfo_ch[37]);
    colUpdate4_ch(blockllr_ch[22],minfo_ch[38],minfo_ch[39],minfo_ch[40],minfo_ch[41]);
    colUpdate4_ch(blockllr_ch[23],minfo_ch[42],minfo_ch[43],minfo_ch[44],minfo_ch[45]);
    colUpdate4_ch(blockllr_ch[24],minfo_ch[46],minfo_ch[47],minfo_ch[48],minfo_ch[49]);
    colUpdate4_ch(blockllr_ch[25],minfo_ch[50],minfo_ch[51],minfo_ch[52],minfo_ch[53]);
    colUpdate4_ch(blockllr_ch[26],minfo_ch[54],minfo_ch[55],minfo_ch[56],minfo_ch[57]);
    colUpdate4_ch(blockllr_ch[27],minfo_ch[58],minfo_ch[59],minfo_ch[60],minfo_ch[61]);
    colUpdate4_ch(blockllr_ch[28],minfo_ch[62],minfo_ch[63],minfo_ch[64],minfo_ch[65]);
    colUpdate4_ch(blockllr_ch[29],minfo_ch[66],minfo_ch[67],minfo_ch[68],minfo_ch[69]);
    //with I_sc2cc
    colUpdate3_I_ch(blockllr_ch[30],blockllr_src_2_ch[0] ,minfo_ch[70] ,minfo_ch[71] ,minfo_ch[72]);
    colUpdate3_I_ch(blockllr_ch[31],blockllr_src_2_ch[1] ,minfo_ch[73] ,minfo_ch[74] ,minfo_ch[75]);
    colUpdate3_I_ch(blockllr_ch[32],blockllr_src_2_ch[2] ,minfo_ch[76] ,minfo_ch[77] ,minfo_ch[78]);
    colUpdate3_I_ch(blockllr_ch[33],blockllr_src_2_ch[3] ,minfo_ch[79] ,minfo_ch[80] ,minfo_ch[81]);
    colUpdate3_I_ch(blockllr_ch[34],blockllr_src_2_ch[4] ,minfo_ch[82] ,minfo_ch[83] ,minfo_ch[84]);
    colUpdate3_I_ch(blockllr_ch[35],blockllr_src_2_ch[5] ,minfo_ch[85] ,minfo_ch[86] ,minfo_ch[87]);
    colUpdate3_I_ch(blockllr_ch[36],blockllr_src_2_ch[6] ,minfo_ch[88] ,minfo_ch[89] ,minfo_ch[90]);
    colUpdate3_I_ch(blockllr_ch[37],blockllr_src_2_ch[7] ,minfo_ch[91] ,minfo_ch[92] ,minfo_ch[93]);
    colUpdate3_I_ch(blockllr_ch[38],blockllr_src_2_ch[8] ,minfo_ch[94] ,minfo_ch[95] ,minfo_ch[96]);
    colUpdate3_I_ch(blockllr_ch[39],blockllr_src_2_ch[9] ,minfo_ch[97] ,minfo_ch[98] ,minfo_ch[99]);
    colUpdate3_I_ch(blockllr_ch[40],blockllr_src_2_ch[10],minfo_ch[100],minfo_ch[101],minfo_ch[102]);
    colUpdate3_I_ch(blockllr_ch[41],blockllr_src_2_ch[11],minfo_ch[103],minfo_ch[104],minfo_ch[105]);
    colUpdate3_I_ch(blockllr_ch[42],blockllr_src_2_ch[12],minfo_ch[106],minfo_ch[107],minfo_ch[108]);
    colUpdate3_I_ch(blockllr_ch[43],blockllr_src_2_ch[13],minfo_ch[109],minfo_ch[110],minfo_ch[111]);
    colUpdate3_I_ch(blockllr_ch[44],blockllr_src_2_ch[14],minfo_ch[112],minfo_ch[113],minfo_ch[114]);
    colUpdate3_I_ch(blockllr_ch[45],blockllr_src_2_ch[15],minfo_ch[115],minfo_ch[116],minfo_ch[117]);
    colUpdate3_I_ch(blockllr_ch[46],blockllr_src_2_ch[16],minfo_ch[118],minfo_ch[119],minfo_ch[120]);
    colUpdate3_I_ch(blockllr_ch[47],blockllr_src_2_ch[17],minfo_ch[121],minfo_ch[122],minfo_ch[123]);
    colUpdate3_I_ch(blockllr_ch[48],blockllr_src_2_ch[18],minfo_ch[124],minfo_ch[125],minfo_ch[126]);
    colUpdate3_I_ch(blockllr_ch[49],blockllr_src_2_ch[19],minfo_ch[127],minfo_ch[128],minfo_ch[129]);


    //////////////////////Row update/////////////////////

    for(int i=0;i<BL;i++){
    ////#pragma HLS DEPENDENCE variable=minfo_ch inter false
    //#pragma HLS PIPELINE
        ARRAY8   a[30];
        ARRAY8   b[30];
        for(int j=0;j<30;j++){
    //#pragma HLS UNROLL factor=2
            if (j<10) {
                for(int k=0;k<8;k++){
    //#pragma HLS UNROLL
                    if(k<2)
                        a[j].a[k] = minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL];
                    else
                        a[j].a[k] = 31;
                }
                b[j] = rowUpdate8(a[j]);
            }
            else if ((j>9) && (j<20)){
                for(int k=0;k<8;k++){
    //#pragma HLS UNROLL
                    if(k<5)
                        a[j].a[k] = minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL];
                    else
                       a[j].a[k] = 31;
                }
                b[j] = rowUpdate8(a[j]);
            }
            else {
                for(int k=0;k<8;k++){
    //#pragma HLS UNROLL
                    if(k<6)
                        a[j].a[k] = minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL];
                    else
                    	a[j].a[k] = 31;
                }
                b[j] = rowUpdate8(a[j]);
            }




            if (j<10) {
                for(int k=0;k<2;k++){
    //#pragma HLS UNROLL
                    minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL] = b[j].a[k];
                }
            }
            else if ((j>9) && (j<20)){
                for(int k=0;k<5;k++){
    //#pragma HLS UNROLL
                    minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL] = b[j].a[k];
                }
            }
            else {
                for(int k=0;k<6;k++){
    //#pragma HLS UNROLL
                    minfo_ch[rowPara_ch[j][k]][(pidx_ch[rowPara_ch[j][k]]+i)%BL] = b[j].a[k];
                }
            }
        }
    }

    //Update llr_ch_2_src
    llr_ch_2_src_update(blockllr_ch[30],minfo_ch[70] ,minfo_ch[71] ,minfo_ch[72] ,blockllr_ch_2_src[0]) ;
    llr_ch_2_src_update(blockllr_ch[31],minfo_ch[73] ,minfo_ch[74] ,minfo_ch[75] ,blockllr_ch_2_src[1]) ;
    llr_ch_2_src_update(blockllr_ch[32],minfo_ch[76] ,minfo_ch[77] ,minfo_ch[78] ,blockllr_ch_2_src[2]) ;
    llr_ch_2_src_update(blockllr_ch[33],minfo_ch[79] ,minfo_ch[80] ,minfo_ch[81] ,blockllr_ch_2_src[3]) ;
    llr_ch_2_src_update(blockllr_ch[34],minfo_ch[82] ,minfo_ch[83] ,minfo_ch[84] ,blockllr_ch_2_src[4]) ;
    llr_ch_2_src_update(blockllr_ch[35],minfo_ch[85] ,minfo_ch[86] ,minfo_ch[87] ,blockllr_ch_2_src[5]) ;
    llr_ch_2_src_update(blockllr_ch[36],minfo_ch[88] ,minfo_ch[89] ,minfo_ch[90] ,blockllr_ch_2_src[6]) ;
    llr_ch_2_src_update(blockllr_ch[37],minfo_ch[91] ,minfo_ch[92] ,minfo_ch[93] ,blockllr_ch_2_src[7]) ;
    llr_ch_2_src_update(blockllr_ch[38],minfo_ch[94] ,minfo_ch[95] ,minfo_ch[96] ,blockllr_ch_2_src[8]) ;
    llr_ch_2_src_update(blockllr_ch[39],minfo_ch[97] ,minfo_ch[98] ,minfo_ch[99] ,blockllr_ch_2_src[9]) ;
    llr_ch_2_src_update(blockllr_ch[40],minfo_ch[100],minfo_ch[101],minfo_ch[102],blockllr_ch_2_src[10]);
    llr_ch_2_src_update(blockllr_ch[41],minfo_ch[103],minfo_ch[104],minfo_ch[105],blockllr_ch_2_src[11]);
    llr_ch_2_src_update(blockllr_ch[42],minfo_ch[106],minfo_ch[107],minfo_ch[108],blockllr_ch_2_src[12]);
    llr_ch_2_src_update(blockllr_ch[43],minfo_ch[109],minfo_ch[110],minfo_ch[111],blockllr_ch_2_src[13]);
    llr_ch_2_src_update(blockllr_ch[44],minfo_ch[112],minfo_ch[113],minfo_ch[114],blockllr_ch_2_src[14]);
    llr_ch_2_src_update(blockllr_ch[45],minfo_ch[115],minfo_ch[116],minfo_ch[117],blockllr_ch_2_src[15]);
    llr_ch_2_src_update(blockllr_ch[46],minfo_ch[118],minfo_ch[119],minfo_ch[120],blockllr_ch_2_src[16]);
    llr_ch_2_src_update(blockllr_ch[47],minfo_ch[121],minfo_ch[122],minfo_ch[123],blockllr_ch_2_src[17]);
    llr_ch_2_src_update(blockllr_ch[48],minfo_ch[124],minfo_ch[125],minfo_ch[126],blockllr_ch_2_src[18]);
    llr_ch_2_src_update(blockllr_ch[49],minfo_ch[127],minfo_ch[128],minfo_ch[129],blockllr_ch_2_src[19]);

    //Update llr_ch_2_src

    for(int p=0;p<20;p++){		//Ns/BL
        for(int q=0;q<BL;q++){         //BL=160
//#pragma HLS PIPELINE
        	ap_int<6> s = blockllr_ch_2_src[p][q];
            llr_ch_2_src[p*BL+q] = s;
        }
    }
}

void ldpcDec(ap_int<6> llr_ch[8000], ap_int<6> llr_src[6400], bool output[6400]){
#pragma HLS INTERFACE axis register both port=llr_ch
#pragma HLS INTERFACE axis register both port=llr_src
#pragma HLS INTERFACE axis register both port=output
    ap_int<6> minfo_src[285][256];
    ap_int<6> minfo_ch[130][256];
    ap_int<6> blockllr_src[40][256];
    ap_int<6> blockllr_ch[50][256];
    ap_int<6> llr_ch_2_src[3200];
    ap_int<6> llr_src_2_ch[3200];
    bool blockdout_src[40][256];

//Initialization

    readSrcData(llr_src,minfo_src,blockllr_src,llr_src_2_ch);
    readChData(llr_ch,minfo_ch,blockllr_ch,llr_ch_2_src);

//Decode

    for(int iter_num=0;iter_num<ITERNUM;iter_num++){
//#pragma HLS PIPELINE
        updateSrcMinfo(minfo_src,blockllr_src,llr_src_2_ch,llr_ch_2_src,blockdout_src);
        updateChMinfo(minfo_ch,blockllr_ch,llr_src_2_ch,llr_ch_2_src);
    }

//Output decoded data

    int cnt = 0;
    for(int i=0;i<40;i++){
    	for(int j=0;j<BL;j++){
//#pragma HLS PIPELINE
            output[cnt] = blockdout_src[i][j];
	    cnt++;
    	}
    }
}


inline ARRAY2 compMin(ap_int<6> a,ap_int<6> b,ap_int<6> c,ap_int<6> d){
	ARRAY2 res;
	if(a<c){
		res.a1 = a;
		if(b<c)
			res.a2 = b;
		else
			res.a2 = c;
	}
	else{
		res.a1 = c;
		if(a<d)
			res.a2 = a;
		else
			res.a2 = d;
	}
	return res;
}


inline ARRAY16_2 rowUpdate16(ARRAY16 a){
//#pragma HLS PIPELINE
//#pragma HLS ARRAY_PARTITION variable=a complete dim=1
	bool mark1[16];
	ap_int<6> a1[16];
	for(int i=0;i<16;i++){
//#pragma HLS UNROLL
		if(a.a[i]<0){
		    mark1[i] = false;
		    a1[i] =  (-a.a[i])-((-a.a[i])>>3)-((-a.a[i])>>4);
		}
		else{
		    mark1[i] = true;
		    a1[i] =  a.a[i] - (a.a[i]>>3) - (a.a[i]>>4);
		}
	}
	ap_int<6> a2[16];
	for(int i=0;i<8;i++){
//#pragma HLS UNROLL
		if(a1[2*i]<a1[2*i+1]){
		    a2[2*i] = a1[2*i];
		    a2[2*i+1] = a1[2*i+1];
		}
		else{
		    a2[2*i] = a1[2*i+1];
		    a2[2*i+1] = a1[2*i];
		}
	}



	ARRAY2 a3[4];
	a3[0] = compMin(a2[0] ,a2[1] ,a2[2] ,a2[3] );
	a3[1] = compMin(a2[4] ,a2[5] ,a2[6] ,a2[7] );
    a3[2] = compMin(a2[8] ,a2[9] ,a2[10],a2[11]);
    a3[3] = compMin(a2[12],a2[13],a2[14],a2[15]);



	ARRAY2 a4[2];
	a4[0] = compMin(a3[0].a1,a3[0].a2,a3[1].a1,a3[1].a2);
	a4[1] = compMin(a3[2].a1,a3[2].a2,a3[3].a1,a3[3].a2);
	ARRAY2 a5;
	a5 = compMin(a4[0].a1,a4[0].a2,a4[1].a1,a4[1].a2);
	bool marka = true;
	for(int i=0;i<16;i++){
//#pragma HLS UNROLL
        marka = marka==mark1[i];
	}
	ARRAY16_2 res;
//#pragma HLS ARRAY_PARTITION variable=res complete dim=1
	for(int i=0;i<16;i++){
//#pragma HLS UNROLL
	    if(marka==mark1[i]){
	    	if(a5.a1==a1[i])
	    	    res.a[i] = a5.a2;
	    	else
	    	    res.a[i] = a5.a1;
	    }
	    else{
	    	if(a5.a1==a1[i])
	    	    res.a[i] = -a5.a2;
	    	else
	    	    res.a[i] = -a5.a1;
	    }
	}
//I sc or cc output


    if(marka==mark1[15]){
    	if(a5.a1==a1[15])
    	    res.i_sc_or_cc = a5.a2;
    	else
    	    res.i_sc_or_cc = a5.a1;
    }
    else{
    	if(a5.a1==a1[15])
    	    res.i_sc_or_cc = -a5.a2;
    	else
    	    res.i_sc_or_cc = -a5.a1;
    }

	return res;
}

inline ARRAY8 rowUpdate8(ARRAY8 a){
//#pragma HLS PIPELINE
//#pragma HLS ARRAY_PARTITION variable=a complete dim=1
	bool mark1[8];
	ap_int<6> a1[8];
	for(int i=0;i<8;i++){
//#pragma HLS UNROLL
		if(a.a[i]<0){
			mark1[i] = false;
			a1[i] =  (-a.a[i])-((-a.a[i])>>3)-((-a.a[i])>>4);
		}
		else{
			mark1[i] = true;
			a1[i] =  a.a[i] - (a.a[i]>>3) - (a.a[i]>>4);
		}
	}
	ap_int<6> a2[8];
	for(int i=0;i<4;i++){
//#pragma HLS UNROLL
		if(a1[2*i]<a1[2*i+1]){
			a2[2*i] = a1[2*i];
			a2[2*i+1] = a1[2*i+1];
		}
		else{
			a2[2*i] = a1[2*i+1];
			a2[2*i+1] = a1[2*i];
		}
	}
	ARRAY2 a3[2];
	a3[0] = compMin(a2[0],a2[1],a2[2],a2[3]);
	a3[1] = compMin(a2[4],a2[5],a2[6],a2[7]);

	ARRAY2 a4;

    a4 = compMin(a3[0].a1,a3[0].a2,a3[1].a1,a3[1].a2);

	bool marka = true;
	for(int i=0;i<8;i++){
//#pragma HLS UNROLL
		marka = marka==mark1[i];
	}
	ARRAY8 res;
//#pragma HLS ARRAY_PARTITION variable=res complete dim=1
	for(int i=0;i<8;i++){
//#pragma HLS UNROLL
		if(marka==mark1[i]){
			if(a4.a1==a1[i])
				res.a[i] = a4.a2;
			else
				res.a[i] = a4.a1;
		}
		else{
			if(a4.a1==a1[i])
				res.a[i] = -a4.a2;
			else
				res.a[i] = -a4.a1;
		}
	}
	return res;
}



inline void colUpdate3_I_ch(ap_int<6> l[256],ap_int<6> blk_i_s2c[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256]){

    for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
        ap_int<6> t[3];
        t[0] = a[i];
        t[1] = b[i];
        t[2] = c[i];
        ap_int<10> sum = l[i] + blk_i_s2c[i] + t[0] + t[1] + t[2];
        ap_int<11> s[3];

//#pragma HLS UNROLL factor=2
        for(int j=0;j<3;j++){
            s[j] = sum - t[j];
            if(s[j] >31)
                s[j] = 31;
            if(s[j] <-32)
                s[j] = -32;
        }
        a[i] = s[0];
        b[i] = s[1];
        c[i] = s[2];

    }

}

inline void llr_ch_2_src_update(ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256],ap_int<6> blk_i_c2s[256]){
    for(int i=0;i<BL;i++){

        ap_int<9> blk_i_c2s_tmp = l[i] + a[i] + b[i] + c[i];

        if (blk_i_c2s_tmp > 31)
        	blk_i_c2s_tmp = 31;
        if (blk_i_c2s_tmp <-31)
        	blk_i_c2s_tmp = -31;

        blk_i_c2s[i] = blk_i_c2s_tmp;
    }
}

inline void colUpdate_ch(ap_int<6> l[256],ap_int<6> a[256]){

    for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
//        ap_int<6> t;
//        t = a[i];
//        ap_int<7> sum = l[i] + t;
//        ap_int<8> s;
//
//        s = sum - t;
//        if(s >31)
//            s = 31;
//        if(s <-32)
//            s = -32;
//
//        a[i] = s;
    	a[i] = l[i];
    }

}

inline void colUpdate2_ch(ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[2];
		t[0] = a[i];
		t[1] = b[i];
		ap_int<8> sum = l[i] + t[0] + t[1];
		ap_int<9> s[2];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<2;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
	}
}

inline void colUpdate4_ch(ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256],ap_int<6> d[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[4];
		t[0] = a[i];
		t[1] = b[i];
		t[2] = c[i];
		t[3] = d[i];
		ap_int<10> sum = l[i] + t[0] + t[1] + t[2] + t[3];
		ap_int<11> s[4];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<4;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
		c[i] = s[2];
		d[i] = s[3];
	}
}

inline void colUpdate15(bool r[256],ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256],ap_int<6> d[256],ap_int<6> e[256],ap_int<6> f[256],ap_int<6> g[256],ap_int<6> h[256],ap_int<6> k[256],ap_int<6> m[256], ap_int<6> n[256],ap_int<6> p[256], ap_int<6> q[256], ap_int<6> z[256],ap_int<6> u[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[15];
		t[0]  = a[i];
		t[1]  = b[i];
        t[2]  = c[i];
        t[3]  = d[i];
        t[4]  = e[i];
        t[5]  = f[i];
        t[6]  = g[i];
        t[7]  = h[i];
        t[8]  = k[i];
        t[9]  = m[i];
        t[10] = n[i];
        t[11] = p[i];
        t[12] = q[i];
        t[13] = z[i];
        t[14] = u[i];
		ap_int<21> sum = l[i]+t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9]+t[10]+t[11]+t[12]+t[13]+t[14];
		ap_int<22> s[15];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<15;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
        c[i] = s[2];
        d[i] = s[3];
        e[i] = s[4];
        f[i] = s[5];
        g[i] = s[6];
        h[i] = s[7];
        k[i] = s[8];
        m[i] = s[9];
        n[i] = s[10];
        p[i] = s[11];
        q[i] = s[12];
        z[i] = s[13];
        u[i] = s[14];
		r[i] = sum<0;
	}
}

inline void colUpdate11(bool r[256],ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256],ap_int<6> d[256],ap_int<6> e[256],ap_int<6> f[256],ap_int<6> g[256],ap_int<6> h[256],ap_int<6> k[256],ap_int<6> m[256],ap_int<6> n[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[11];
		t[0]  = a[i];
		t[1]  = b[i];
        t[2]  = c[i];
        t[3]  = d[i];
        t[4]  = e[i];
        t[5]  = f[i];
        t[6]  = g[i];
        t[7]  = h[i];
        t[8]  = k[i];
        t[9]  = m[i];
        t[10] = n[i];
		ap_int<17> sum = l[i]+t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9]+t[10];
		ap_int<18> s[11];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<11;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
        c[i] = s[2];
        d[i] = s[3];
        e[i] = s[4];
        f[i] = s[5];
        g[i] = s[6];
        h[i] = s[7];
        k[i] = s[8];
        m[i] = s[9];
        n[i] = s[10];
		r[i] = sum<0;
	}
}

inline void colUpdate19(bool r[256],ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256],ap_int<6> d[256],ap_int<6> e[256],ap_int<6> f[256],ap_int<6> g[256],ap_int<6> h[256],ap_int<6> k[256],ap_int<6> m[256], ap_int<6> n[256],ap_int<6> p[256], ap_int<6> q[256], ap_int<6> z[256],ap_int<6> u[256],ap_int<6> v[256],ap_int<6> w[256],ap_int<6> x[256],ap_int<6> y[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[19];
		t[0]  = a[i];
		t[1]  = b[i];
        t[2]  = c[i];
        t[3]  = d[i];
        t[4]  = e[i];
        t[5]  = f[i];
        t[6]  = g[i];
        t[7]  = h[i];
        t[8]  = k[i];
        t[9]  = m[i];
        t[10] = n[i];
        t[11] = p[i];
        t[12] = q[i];
        t[13] = z[i];
        t[14] = u[i];
        t[15] = v[i];
        t[16] = w[i];
        t[17] = x[i];
        t[18] = y[i];
		ap_int<25> sum = l[i]+t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9]+t[10]+t[11]+t[12]+t[13]+t[14]+t[15]+t[16]+t[17]+t[18];
		ap_int<26> s[19];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<19;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
        c[i] = s[2];
        d[i] = s[3];
        e[i] = s[4];
        f[i] = s[5];
        g[i] = s[6];
        h[i] = s[7];
        k[i] = s[8];
        m[i] = s[9];
        n[i] = s[10];
        p[i] = s[11];
        q[i] = s[12];
        z[i] = s[13];
        u[i] = s[14];
        v[i] = s[15];
        w[i] = s[16];
        x[i] = s[17];
        y[i] = s[18];
		r[i] = sum<0;
	}
}

inline void colUpdate3(bool r[256],ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256],ap_int<6> c[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[3];
		t[0] = a[i];
		t[1] = b[i];
        t[2] = c[i];
		ap_int<9> sum = l[i] + t[0] + t[1] + t[2];
		ap_int<10> s[3];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<3;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
        c[i] = s[2];
		r[i] = sum<0;
	}
}

inline void colUpdate2(bool r[256],ap_int<6> l[256],ap_int<6> a[256],ap_int<6> b[256]){
	for(int i=0;i<BL;i++){
//#pragma HLS PIPELINE
		ap_int<6> t[2];
		t[0] = a[i];
		t[1] = b[i];
		ap_int<8> sum = l[i] + t[0] + t[1];
		ap_int<9> s[2];
//#pragma HLS UNROLL factor=2
		for(int j=0;j<2;j++){
			s[j] = sum - t[j];
			if(s[j]>31)
				s[j] = 31;
			if(s[j]<-32)
				s[j] = -32;
		}
		a[i] = s[0];
		b[i] = s[1];
		r[i] = sum<0;
	}
}


