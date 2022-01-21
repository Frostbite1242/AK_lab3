#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <chrono>
#include <ctime>
#include <unistd.h>

using namespace std;

void help();
void info();
void personale();


int main(int argc, char *argv[]) {
    int rez = -1;
    int option_index;
    const char* short_options = "hda";
    const struct option long_options[] = {
            {"help",no_argument,NULL,'h'},
            {"info",no_argument,NULL,'i'},
            {"personale",no_argument,NULL,'p'},
            {NULL,0,NULL,0}
    };
    int h_counter = 1;
    int i_counter = 1;
    int p_count = 1;


    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index))  != -1) {
        switch(rez){
            case 'h': {
                if (h_counter < 1){
                    goto exitH;
                }
                h_counter--;
                help();
                exitH: break;
            }
            case 'i': {
                if (d_counter < 1){
                    goto exitV;
                }
                d_counter--;
                info();

                exitV: break;
            }

            case 'p': {
                if (a_count < 1){
                    goto exitA;
                }
                a_count--;
                personale();

                exitA: break;
            }

            case '?': default: {
                printf("Option not supported\n");
                break;
            }
        }
    }
}

void help()
{
    printf("-h (--help) виводить підсказку\n"
           "-p (--personale) росповідае факти\n"
           "-i (--info) інформація про автора\n");
}

void info()
{
    printf("Самая крупная жемчужина в мире достигает 6 килограммов в весе.\n\n");
    usleep (3000000);
    printf("Законодательство США допускало отправку детей по почте до 1913 года.\n\n");
    usleep (3000000);
    printf("В языке древних греков не существовало слова, которое обозначало религию.\n\n");
    usleep (3000000);
    printf("В современной истории есть промежуток времени, когда на счетах компании «Apple», было больше средств, чем у американского правительства.\n");
    usleep (2000000);
}

void personale(){
    printf("Petruk Stanislav +380638163348\n");
}
