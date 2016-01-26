#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary Shuffle
// By Nathan Ross

void dumphex_file(char *name);
void hexdump(unsigned char *buffer, unsigned long index, unsigned long width);
int dumphex_file2(char *name, unsigned long start, unsigned long stop, unsigned long width);
void loadfile(char *name);
void shuffle_file(char *name);
void unshuffle_file(char *name);
void add_file(char *name);
void subtract_file(char *name);
void dump_buffer(void *buffer, unsigned long buffer_size);
void dump_buffer_hex(void *buffer, unsigned long buffer_size);
unsigned long get_rand(unsigned long size);
unsigned long get_rand2(unsigned long size);
void get_rand_test(void);
char* shuffle_buffer(char *buffer, unsigned long buffer_size);
char* unshuffle_buffer(char *buffer, unsigned long *unshuffle, unsigned long buffer_size);
char* add_buffer(char *buffer, unsigned long buffer_size);
char* sub_buffer(char *buffer, unsigned long buffer_size);
void write_buffer(char *name, char *buffer, unsigned long buffer_size);
void write_shuffle_buffer(char *name, char *buffer, unsigned long buffer_size);
void write_unshuffle_buffer(char *name, char *buffer, unsigned long buffer_size);
void write_add_buffer(char *name, char *buffer, unsigned long buffer_size);
void write_sub_buffer(char *name, char *buffer, unsigned long buffer_size);

unsigned long timeslast     = 10;
static unsigned long nSeed  = 100;
static unsigned long nSeed2 = 100;
static unsigned long sum    = 0;

// process the command line arguments
int main(int argc, char *argv[]) {
    // loadfile("alpha.txt");

    // get_rand_test();

    printf("Shuffle arguments %d\n", argc);

    if ( argc < 3 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s -rev filename\n", argv[0] ); // reverse file
        printf( "usage: %s -hex filename\n\n", argv[0] );

        printf( "usage: %s -sh  filename\n", argv[0] );
        printf( "usage: %s -ush filename\n", argv[0] );

        printf( "usage: %s -add filename\n", argv[0] );
        printf( "usage: %s -sub filename\n\n", argv[0] );
        printf( "usage: %s -add number filename\n", argv[0] );
        printf( "usage: %s -sub number filename\n\n", argv[0] );
        printf( "usage: %s -sh  seed iterations filename\n", argv[0] );
        printf( "usage: %s -ush seed iterations filename\n", argv[0] );
        exit(1);
    }
    else if (argc == 3) {
        if (strcmp(argv[1], "-sh") == 0)  /* Process optional arguments. */
        {
          shuffle_file(argv[2]);
        }
        if (strcmp(argv[1], "-ush") == 0)  /* Process optional arguments. */
        {
          unshuffle_file(argv[2]);
        }

        if (strcmp(argv[1], "-hex") == 0)  /* Process optional arguments. */
        {
          // dumphex_file(argv[2]);
          dumphex_file2(argv[2],0, 16, 16);
        }
        if (strcmp(argv[1], "-rev") == 0)  /* Process optional arguments. */
        {
          reverse_file(argv[2]);
        }
        if (strcmp(argv[1], "-add") == 0)  
        {
          add_file(argv[2]);
        }

        if (strcmp(argv[1], "-sub") == 0)  
        {
          subtract_file(argv[2]);
        }

    }
    else if (argc == 4) {
        unsigned long sum = atoi(argv[2]);
        if (strcmp(argv[1], "-add") == 0)
        {
          add_file(argv[3]);
        }

        if (strcmp(argv[1], "-sub") == 0)
        {
          subtract_file(argv[3]);
        }

    }
    if (argc == 5 ) {
        unsigned long seed       = atoi(argv[2]); 
        unsigned long iterations = atoi(argv[3]);
        nSeed  = seed; 
        nSeed2 = seed; 
        timeslast  = iterations; 
        timeslast  = iterations; 
        if (strcmp(argv[1], "-sh") == 0)  /* Process optional arguments. */
        {
          shuffle_file(argv[4]);
        }
        if (strcmp(argv[1], "-ush") == 0)  /* Process optional arguments. */
        {
          unshuffle_file(argv[4]);
        }
 

    }

    return 0;
}

// load a file into memory and run the buffer tests
void loadfile(char *name)
{

	FILE *file;
	char *buffer;
	unsigned long fileLen;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s\n", name);
		return;
	}
	
	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer=(char *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
                                fclose(file);
		return;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

        // process the buffer
        dump_buffer_hex(buffer, fileLen);
        shuffle_buffer(buffer, fileLen);
        
        printf("\npost shuffle buffer\n");
        dump_buffer_hex(buffer, fileLen);

        printf("\npost unshuffle buffer\n");
        write_buffer(name, buffer, fileLen);
        // unshuffle_buffer(buffer, fileLen);
        dump_buffer_hex(buffer, fileLen);

	free(buffer);
}

// dump the contents of a file or buffer as hex
dumphex_file(char *name)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        dump_buffer_hex(buffer, fileLen);

        free(buffer);
}

void hexdump(unsigned char *buffer, unsigned long index, unsigned long width)
{
  unsigned long i;
  unsigned long spacer;
  for (i=0;i<index;i++)
  {
    printf("%02x ",buffer[i]);
  }
  for (spacer=index;spacer<width;spacer++)
  printf("	");
  printf(": ");
  for (i=0;i<index;i++)
  {
    if (buffer[i] < 32) { 
        printf(".");
    }
    else {
      if (buffer[i] != '\n') {
         printf("%c",buffer[i]);
      }
      else {
         printf(" ");
      }
    }
  }
  printf("\n");
}

int dumphex_file2(char *name,unsigned long start, unsigned long stop, unsigned long width)
{
  char ch;
  unsigned long f_index=0;
  unsigned long bb_index=0;
  unsigned char *byte_buffer = malloc(width);

  FILE *infile;
  // Open file
  infile = fopen(name, "rb");
  if (!infile)
  {
       fprintf(stderr, "Unable to open file %s\n", name);
       return;
  }

  if (byte_buffer == NULL)
  {
	printf("Could not allocate memory for byte_buffer\n");
	return -1;
  }
  while (!feof(infile))
  {
	ch = getc(infile);	
	byte_buffer[bb_index] = ch;
	bb_index++;
	if (bb_index >= width)
	{
	  hexdump(byte_buffer,bb_index,width);
	  bb_index=0;
	}	
	f_index++;	
  }
  if (bb_index)
	hexdump(byte_buffer,bb_index,width);
  fclose(infile);
  free(byte_buffer);
  return 0;
}

// shuffle a file
void shuffle_file(char *name)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        printf("shuffle file size %lu \n", fileLen); 

        int times = 0;
        unsigned long seed = nSeed;
        for (times = 0; times < timeslast; times++) {     
          printf("shuffle file %lu \n", times);   
          shuffle_buffer(buffer, fileLen);
          nSeed  = seed;
          nSeed2 = seed;
        }
        write_shuffle_buffer(name, buffer, fileLen);
        // dump_buffer_hex(buffer, fileLen);

        free(buffer);
}

// unshuffle a file
void unshuffle_file(char *name)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        // unsigned long size = fileLen + 1;
        unsigned long size = fileLen;
        unsigned long unshuffle_size = fileLen + 1;
        unsigned long *unshuffle;
        //Allocate memory
        unshuffle=(long *)malloc(size*sizeof(unsigned long));
        if (!unshuffle)
        {
             fprintf(stderr, "Memory error!");
             return;
        }

        int times = 0;
        unsigned long seed = nSeed;
        for (times = 0; times < timeslast; times++) {
           printf("unshuffle file %lu \n", times);
           unshuffle_buffer(buffer, unshuffle, fileLen);
           nSeed = seed;
           nSeed2 = seed;
        }
        write_unshuffle_buffer(name, buffer, fileLen);
        // dump_buffer_hex(buffer, fileLen);


        free(buffer);
        free(unshuffle);
}

void add_file(char *name)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        printf("shuffle file size %lu \n", fileLen);

        int times = 0;
        unsigned long seed = nSeed;
        for (times = 0; times < timeslast; times++) {
          printf("shuffle file %lu \n", times);
          add_buffer(buffer, fileLen);
          nSeed  = seed;
          nSeed2 = seed;
        }
        write_add_buffer(name, buffer, fileLen);
        // dump_buffer_hex(buffer, fileLen);

        free(buffer);
}

void subtract_file(char *name)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        printf("shuffle file size %lu \n", fileLen);

        int times = 0;
        unsigned long seed = nSeed;
        for (times = 0; times < timeslast; times++) {
          printf("shuffle file %lu \n", times);
          sub_buffer(buffer, fileLen);
          nSeed  = seed;
          nSeed2 = seed;
        }
        write_sub_buffer(name, buffer, fileLen);
        // dump_buffer_hex(buffer, fileLen);

        free(buffer);
}



// print out the buffer
void dump_buffer(void *buffer, unsigned long buffer_size)
{
  int i;

  for(i = 0;i < buffer_size;++i)
     printf("%c", ((char *)buffer)[i]);
}

// dump the hex encoding of a file
void dump_buffer_hex(void *buffer, unsigned long buffer_size)
{ 
  int c = 0;
  for (c=0;c<buffer_size;c++)
  {
     printf("%.2X", ((char *)buffer)[c]);

     // put an extra space between every 4 bytes
     if (c % 4 == 3)
     {
         printf(" ");
     }

     // Display 16 bytes per line
     if (c % 16 == 15)
     {
         printf("\n");
     }
  }
  // Add an extra new line
  printf("\n");
}

// shuffle random function
unsigned long get_rand(unsigned long size)
{
    // Use the current seed and generate a new value from it
    nSeed = (8253729 * nSeed + 2396403); 

    // Use the seed and return a value between 0 and the file buffer size
    return nSeed  % size;
}

// unshuffle random function
unsigned long get_rand2(unsigned long size)
{
    // Use the current seed and generate a new value from it
    nSeed2 = (8253729 * nSeed2 + 2396403);

    // Use the seed and return a value between 0 and the file buffer size 
    return nSeed2  % size;
}

// test the get_rand functions
void get_rand_test(void)
{
    int nCount = 0;

    for (nCount=0; nCount < 100; ++nCount)
    {
        // printf("%x%s", get_rand(32000), "\t");
        printf("%i%s", get_rand(32000), "\t");

        // If we've printed 5 numbers, start a new column
        if ((nCount+1) % 5 == 0)
            printf("%s", "\n");
    }
}

// shuffle the buffer
char* shuffle_buffer(char *buffer, unsigned long buffer_size)
{
  unsigned long cx = 0;
  unsigned long c = 0;
  unsigned long swap = 0;
  char a;
  char b;
  // unsigned long shuffle_size = buffer_size * 1000;
  for (c=0;c<buffer_size;c++)
  // for (c=0;c<shuffle_size;c++)
  {
     // for (cx = 0; cx < 100; cx++) { // test one shuffle improvement
     // printf("testing improvement %lu %lu\n", c, cx);
     swap = get_rand(buffer_size);
     a = (char )buffer[c];
     b = (char )buffer[swap];
     buffer[swap] = a;
     buffer[c] = b;
 
     // } // test one

  }

  // dump_buffer_hex(buffer, buffer_size);
}


// unshuffle the buffer
char* unshuffle_buffer(char *buffer, unsigned long *unshuffle, unsigned long buffer_size)
{
  unsigned long c = 0;
  unsigned long swap = 0;
  // unsigned long *unshuffle;
  char a;
  char b;


  unsigned long size = buffer_size;   
  unsigned long unshuffle_size = buffer_size;   
  //Allocate memory
  //unshuffle=(long *)malloc(size*sizeof(unsigned long));
  //if (!unshuffle)
  // {
  //     fprintf(stderr, "Memory error!");
  //     return;
  // }


  for (c=0;c<buffer_size;c++)
  {
      // swap = get_rand(buffer_size); 
      // unshuffle[c] = swap;
      unshuffle[c] = get_rand2(buffer_size);
  }

  // for (c=buffer_size -1;c>=0;c--) {
  for (c=buffer_size;c>=0;c--) {
       
       swap = unshuffle[c];
       a = buffer[c];
       b = buffer[swap];

       // printf("testing %lu %i\n", c, swap);
       
       buffer[swap] =  a;
       buffer[c] =  b;
  
       if (c == 0) {
   //        free(unshuffle);
           // return (char *) a;
           return;
       }
  }

  // dump_buffer_hex(buffer, buffer_size);
  // free(unshuffle);
}

// add to the buffer
char* add_buffer(char *buffer, unsigned long buffer_size)
{
  unsigned long c   = 0;
  unsigned long add = sum;
  char a;
  char b;
  // unsigned long shuffle_size = buffer_size * 1000;
  for (c=0;c<buffer_size;c++)
  // for (c=0;c<shuffle_size;c++)
  {
     // printf("testing improvement %lu %lu\n", c, cx);
     if (sum == 0) {
         add = get_rand(buffer_size);
     }
     a = (char )buffer[c] + add;
     buffer[c] = a;

  }

  // dump_buffer_hex(buffer, buffer_size);
}

// add to the buffer
char* sub_buffer(char *buffer, unsigned long buffer_size)
{
  unsigned long c   = 0;
  unsigned long add = sum;
  char a;
  char b;
  // unsigned long shuffle_size = buffer_size * 1000;
  for (c=0;c<buffer_size;c++)
  // for (c=0;c<shuffle_size;c++)
  {
     // printf("testing improvement %lu %lu\n", c, cx);
     if (sum == 0) {
         add = get_rand(buffer_size);
     }
     a = (char )buffer[c] - add;
     buffer[c] = a;

  }

  // dump_buffer_hex(buffer, buffer_size);
}


// reverse file
void reverse_file(char *name) {
  unsigned long loc = 0;
  FILE *in, *out;
  char ch;

  char str[18] = ".reverse";
  size_t message_len = strlen(name) + 12;
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  if((in = fopen(name, "rb")) == NULL) {
    printf("Cannot open input file.\n");
    exit(1);
  }
  if((out = fopen(newname, "wb"))==NULL) {
    printf("Cannot open output file.\n");
    exit(1);
  }

  /* find end of source file */
  fseek(in, 0, SEEK_END);
  loc = ftell(in);

  
  printf ("size = %lu\n", loc);

  /* copy file in reverse order */
  loc = loc-1; /* back up past end-of-file mark */
  
  while(loc >= 0) {
    fseek(in, loc, SEEK_SET);
    ch = fgetc(in);
    fputc(ch, out);
    // break at zero so the unsigned long doesn't wrap and continue
    if (loc == 0) {
       break;
    }
    loc--;
  }
  fclose(in);
  fclose(out);


}

// write buffer
void write_buffer(char *name, char *buffer, unsigned long buffer_size)
{

  FILE* pFile;
  char str[8] = ".test";
  size_t message_len = strlen(name) + 6; /* + 1 for terminating NULL */
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  printf("filename = %s\n", newname);

  pFile = fopen(newname,"wb");

  if (pFile ){
         fwrite(buffer,1,buffer_size,pFile); 
  }
}

// write buffer
void write_unshuffle_buffer(char *name, char *buffer, unsigned long buffer_size)
{

  FILE* pFile;
  char str[18] = ".unshuffle";
  size_t message_len = strlen(name) + 16; /* + 1 for terminating NULL */
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  printf("filename = %s\n", newname);

  pFile = fopen(newname,"wb");

  if (pFile ){
         fwrite(buffer,1,buffer_size,pFile);
  }
}

// write buffer
void write_shuffle_buffer(char *name, char *buffer, unsigned long buffer_size)
{

  FILE* pFile;
  char str[18] = ".shuffle";
  size_t message_len = strlen(name) + 16; /* + 1 for terminating NULL */
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  printf("filename = %s\n", newname);

  pFile = fopen(newname,"wb");

  if (pFile ){
         fwrite(buffer,1,buffer_size,pFile);
  }
}

// write buffer
void write_add_buffer(char *name, char *buffer, unsigned long buffer_size)
{

  FILE* pFile;
  char str[18] = ".add";
  size_t message_len = strlen(name) + 16; /* + 1 for terminating NULL */
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  printf("filename = %s\n", newname);

  pFile = fopen(newname,"wb");

  if (pFile ){
         fwrite(buffer,1,buffer_size,pFile);
  }
}

// write buffer
void write_sub_buffer(char *name, char *buffer, unsigned long buffer_size)
{

  FILE* pFile;
  char str[18] = ".sub";
  size_t message_len = strlen(name) + 16; /* + 1 for terminating NULL */
  char *newname = (char*) malloc(message_len);
  strcpy(newname, name);
  strcat(newname, str);

  printf("filename = %s\n", newname);

  pFile = fopen(newname,"wb");

  if (pFile ){
         fwrite(buffer,1,buffer_size,pFile);
  }
}



