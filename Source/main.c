

/* Durvasav Threading                                  */
/* My first threading experiment                       */
/* Success on 11:26 IST, 07-03-2013                    */
/* Experimenting with bruteforce for Durvasav          */
/* Requires pthreadGC2.dll to run                      */
/* Intakes a hash and bruteforced by multiple threads  */


/****************************************************************************

	Name: POSIX Threads Experiment
	Copyright (c) 2013 Vishnu M Aiea
	E-mail : vishnumaiea@gmail.com
	Web : www.vishnumaiea.in
	Date: 22:13 IST, 05-04-2013 
	Description: Multi-threading experiment with pthreads for Durvasav BfPC

****************************************************************************/


/* 22:12 IST, 05-04-2013  */


#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <openssl/md5.h>

#define NUMTHREADS 6


struct thrd_data {

	int tsklmt; /* task limit : position in the charset */
	int begin;  /* beginning of selected charset */
	int start,stop; /* start and stop on charset for each thread */
	char output[7]; /* permutation output */
	char hashin[33]; /* hash intake */
	pthread_t thrd_id; /* unique thread id */
	int status; /* status variable for signalling */

} data[NUMTHREADS+1];


void *func_thread1(void *arg) { /* recieving unique pointer for accessing data structure */
	static char charset[53];
	static char hashout[33]; /* output hash */
	unsigned char result[16]; /* ASCII ouput of hash : non-hexadecimal */
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata; /* unique pointer to the structure : local data pointer */

	ldata = (struct thrd_data *) arg; /* assign value */

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin; /* creating local copies */
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0'; /* setting termination */
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							/*printf("%s\n",ldata->output);*/
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) { /* comparing */
								printf("\n\tThread 1 Found ! ");
								for(i=0; i<NUMTHREADS; i++) { /* placing signal for other threads */
									data[i].status=1; /* signal value is 1 */
								}
								pthread_exit(NULL); /* exit after placing signal */
							}

							else if(ldata->status==1) { /* looking his own signal box for signal placed by any other thread  */
								printf("\n\tThread 1 Terminated !"); /* termination when a signal is found */
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 1 Finished ! "); /* finish the job and exit */
								pthread_exit(NULL);
							}
						}
						start = begin; /* resetting start to begin of charset selected */
					}
				}
			}
		}
	}    /* loop ends */
}


void *func_thread2(void *arg) {
	static char charset[53];
	static char hashout[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata;

	ldata = (struct thrd_data *) arg;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin;
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0';
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) {
								printf("\n\tThread 2 Found ! ");
								for(i=0; i<NUMTHREADS; i++) {
									data[i].status=1;
								}
								pthread_exit(NULL);
							}

							else if(ldata->status==1) {
								printf("\n\tThread 2 Terminated !");
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 2 Finished ! ");
								pthread_exit(NULL);
							}
						}
						start = begin;
					}
				}
			}
		}
	}    /* loop ends */
}


void *func_thread3(void *arg) {
	static char charset[53];
	static char hashout[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata;

	ldata = (struct thrd_data *) arg;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin;
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0';
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) {
								printf("\n\tThread 3 Found ! ");
								for(i=0; i<NUMTHREADS; i++) {
									data[i].status=1;
								}
								pthread_exit(NULL);
							}

							else if(ldata->status==1) {
								printf("\n\tThread 3 Terminated !");
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 3 Finished ! ");
								pthread_exit(NULL);
							}
						}
						start = begin;
					}
				}
			}
		}
	}    /* loop ends */
}


void *func_thread4(void *arg) {
	static char charset[53];
	static char hashout[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata;

	ldata = (struct thrd_data *) arg;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin;
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0';
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) {
								printf("\n\tThread 4 Found ! ");
								for(i=0; i<NUMTHREADS; i++) {
									data[i].status=1;
								}
								pthread_exit(NULL);
							}

							else if(ldata->status==1) {
								printf("\n\tThread 4 Terminated !");
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 4 Finished ! ");
								pthread_exit(NULL);
							}
						}
						start = begin;
					}
				}
			}
		}
	}    /* loop ends */
}


void *func_thread5(void *arg) {
	static char charset[53];
	static char hashout[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata;

	ldata = (struct thrd_data *) arg;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin;
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0';
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) {
								printf("\n\tThread 5 Found ! ");
								for(i=0; i<NUMTHREADS; i++) {
									data[i].status=1;
								}
								pthread_exit(NULL);
							}

							else if(ldata->status==1) {
								printf("\n\tThread 5 Terminated !");
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 5 Finished ! ");
								pthread_exit(NULL);
							}
						}
						start = begin;
					}
				}
			}
		}
	}    /* loop ends */
}


void *func_thread6(void *arg) {
	static char charset[53];
	static char hashout[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt,begin;
	struct thrd_data *ldata;

	ldata = (struct thrd_data *) arg;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	begin = ldata->begin;
	start = ldata->start;
	stop = ldata->stop;
	tsklmt = ldata->tsklmt;


	ldata->output[6]='\0';
	for(i=start; i<=stop; i++) {
		ldata->output[0]=charset[i];
		for(j=start; j<=stop; j++) {
			ldata->output[1]=charset[j];
			for(k=start; k<=stop; k++) {
				ldata->output[2]=charset[k];
				for(m=start; m<=stop; m++) {
					ldata->output[3]=charset[m];
					for(n=start; n<=stop; n++) {
						ldata->output[4]=charset[n];
						for(p=start; p<=stop; p++) {
							ldata->output[5]=charset[p];
							MD5(ldata->output,6,result);
							for(h=0; h<16; h++) {
								sprintf(&hashout[h*2],"%02x", result[h]);
							}

							if(strcmp(hashout,ldata->hashin)==0) {
								printf("\n\tThread 6 Found ! ");
								for(i=0; i<NUMTHREADS; i++) {
									data[i].status=1;
								}
								pthread_exit(NULL);
							}

							else if(ldata->status==1) {
								printf("\n\tThread 6 Terminated !");
								pthread_exit(NULL);
							}

							else if(p==n==m==k==j==i==tsklmt) {
								printf("\n\tThread 6 Finished ! ");
								pthread_exit(NULL);
							}
						}
						start = begin;
					}
				}
			}
		}
	}    /* loop ends */
}


int main() {
	int status;
	int begin,end;
	clock_t begins,ends;
	double timespent;
	int lpt,tload,remain; /* load per task, total work load, and remainder */
	static char charset[53];
	static char hashout[33];
	static char hashin[33];
	unsigned char result[16];
	register unsigned int i,j,k,m,n,p,h;
	register unsigned int start,stop,tsklmt;

	strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	printf("\n\n\tAygent543 : POSIX Threads Experiment : Debug View");
	printf("\n\n\n\tCharset : a..Z");
	printf("\n\n\tOutput len : 6");
	printf("\n\n\tInput hash : ");
	scanf("%s",hashin);
	printf("\n\tBegin  End   ");
	scanf("%d%d",&begin,&end);

	for(i=0; i<=NUMTHREADS; i++) { /* distributing copies to threads */
		strcpy(data[i].hashin,hashin);
	}

	//task distribution
	tload = (end-begin); /* total load */
	lpt = tload/NUMTHREADS; /* load per task */
	remain = tload%NUMTHREADS; /* remainder */

	for(i=0; i<NUMTHREADS; i++) { /* filling structure with parameters for threads */
		data[i].start = (lpt*i)+(begin-1);
		data[i].tsklmt = data[i].start+lpt;
		data[i].begin = begin-1;
		data[i].stop = end-1;
	}

	begins = clock(); /* clock starts */

	// create thread
	pthread_create(&data[0].thrd_id,NULL,func_thread1,(void *)&data[0]);
	pthread_create(&data[1].thrd_id,NULL,func_thread2,(void *)&data[1]);
	pthread_create(&data[2].thrd_id,NULL,func_thread3,(void *)&data[2]);
	pthread_create(&data[3].thrd_id,NULL,func_thread4,(void *)&data[3]);
	pthread_create(&data[4].thrd_id,NULL,func_thread5,(void *)&data[4]);
	pthread_create(&data[5].thrd_id,NULL,func_thread6,(void *)&data[5]);

	/*
	for(i=0;i<NUMTHREADS;i++)
	{
		pthread_create(&data[i].thrd_id,NULL,func_thread1,(void *)&data[i]);
	}
	*/
	if(remain>0) { /* reamain work if any, is performed by main thread */
		start = ((lpt*(NUMTHREADS-1))+(begin-1))+lpt; /* please don't ask me !*/
		stop = end-1;
		tsklmt = end-1;
		data[6].tsklmt = end-1;
		data[6].start = start;

		data[6].output[6]='\0';
		for(i=start; i<=stop; i++) {
			data[6].output[0]=charset[i];
			for(j=start; j<=stop; j++) {
				data[6].output[1]=charset[j];
				for(k=start; k<=stop; k++) {
					data[6].output[2]=charset[k];
					for(m=start; m<=stop; m++) {
						data[6].output[3]=charset[m];
						for(n=start; n<=stop; n++) {
							data[6].output[4]=charset[n];
							for(p=start; p<=stop; p++) {
								data[6].output[5]=charset[p];
								MD5(data[6].output,6,result);
								for(h=0; h<16; h++) {
									sprintf(&hashout[h*2],"%02x", result[h]);
								}

								if(strcmp(hashout,hashin)==0) {
									printf("\n\tThread 7 Found ! ");
									for(i=0; i<NUMTHREADS; i++) {
										data[i].status=1;
									}
									goto found_exit; /* jumping unlike other threads where they trminate */
								}

								else if(data[0].status==1) {
									printf("\n\tThread 7 Terminated !");
									goto found_exit;
								}

								else if(p==n==m==k==j==i==tsklmt) {
									printf("\n\tThread 7 Finished ! ");
								}
							}
							start = begin-1; /* not like others */
						}
					}
				}
			}
		}    /* loop ends */
	}

found_exit:

	pthread_join(data[0].thrd_id, (void **)&status);
	pthread_join(data[1].thrd_id, (void **)&status);
	pthread_join(data[2].thrd_id, (void **)&status);
	pthread_join(data[3].thrd_id, (void **)&status);
	pthread_join(data[4].thrd_id, (void **)&status);
	pthread_join(data[5].thrd_id, (void **)&status);

	/*
	for(i=0;i<NUMTHREADS;i++)
	{
		pthread_join(data[i].thrd_id, (void **)&status);
	}
	*/
	ends = clock();
	timespent = (double)(ends-begins)/CLOCKS_PER_SEC;
	printf("\n\n\tTime taken : %f sec",timespent);

	printf("\n\n");
	for(i=0; i<=NUMTHREADS; i++) {
		printf("\t%s ",data[i].output);
	}

	printf("\n\n");
	for(i=0; i<=NUMTHREADS; i++) {
		printf("\t%d ",data[i].start);
	}
	printf("  start");

	printf("\n\n");
	for(i=0; i<=NUMTHREADS; i++) {
		printf("\t%d ",data[i].tsklmt);
	}
	printf("  tsklmt");
	printf("\n\n\t%d  tload",tload);
	printf("\n\n\t%d  lpt",lpt);
	printf("\n\n\t%d  remain",remain);
	printf("\n\n\t%d  status ",status);

	getch();
	return EXIT_SUCCESS;
}

