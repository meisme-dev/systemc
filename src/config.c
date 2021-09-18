#include <fcntl.h>
#include "../libs/tomlc99/toml.h"

#define O_RDWR 02
#define O_CREAT 0100
#define S_IRUSR 0400
#define S_IRGRP S_IRUSR >> 3
#define S_IROTH S_IRUSR >> 3

int main(){
    FILE *file;
    char errbuf[256];
    file = fopen("systemc.conf", "r");
    if(!file){
        perror("An error occured while attempting to open the configuration file");
        open("systemc.conf", O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
        main();
    }
    toml_table_t *parsed_file = toml_parse_file(file, errbuf, sizeof(errbuf));
    fclose(file);

    toml_table_t *options = toml_table_in(parsed_file, "options");
    if (!options) {
        printf("Missing [options]\n");
    }
    
    toml_free(parsed_file);
    return 0;
}
