// qsort() in Array of Pointer to String 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
  
  int cmp(const void *, const void *);
   
   main(void)
   {
       char *s[] = {
	                      "Gaurav",
						                     "Vaibhav",                   
											                    "Garima",
																                   "Amit"
																				                   };
																								                    
																													    qsort( (char*)s, 4 , sizeof(s[0]), cmp);
																														     
																															     int i = 0;
																																     while(i<4)
																																	     {
																																		         printf("\t%s\n",s[i]);
																																				         i++;      
																																						     }
																																							               
																																										        
																																											   }
																																											    
																																												int cmp(const void *x, const void *y)
																																												{
																																												    return(strcmp(*(char**)x,*(char**)y));       
																																													}
