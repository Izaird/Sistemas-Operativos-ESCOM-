#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main(){
    //Creacion De Variables para Ingresar lo que regrese FORK()
    pid_t pid;
    pid_t PidHijos;
    pid_t PidHijos2;
    
    //Impresion De los Datos del Proceso Padre Antes de Iniciar la Creacion de Hijos
    printf("Hola soy el padre\n");
    printf("Mi identificador es: %d\n\n",getpid());
    
    //Inicio de la Creacion De Hijos
    pid = fork();
    if (pid == 0) {
        //Datos Del Primer Hijo
        printf("\tHola soy el proceso hijo\n");
        printf("\tMi proceso padre es: %d\n",getppid());
        printf("\tMi identificador es: %d\n\n",getpid());
            //Creacion de los 3 Hijos del Primer Hijo
            for (int i = 0; i < 3; ++i)
            {   
               PidHijos = fork();
                if (PidHijos ==0)
                {
                    printf("\t\tHola soy el proceso hijo del hijo, %d\n",i+1);
                    printf("\t\tMi proceso padre es: %d\n",getppid());
                    printf("\t\tMi identificador es: %d\n\n",getpid());

                    //Creacion de los 2 Hijos por cada Hijo Creado Anteriormente    
                    for (int i = 0; i < 2; ++i)
                    {   
                        PidHijos2 = fork();
                        if (PidHijos2 ==0)
                        {
                            printf("\t\t\tHola soy el proceso hijo del hijo, %d\n",i+1);
                            printf("\t\t\tMi proceso padre es: %d\n",getppid());
                            printf("\t\t\tMi identificador es: %d\n\n",getpid()); 
                            break;//Se utiliza un break para lograr que solo se ejecuten los hijos necesarios 
                        }
                        else
                            wait(NULL); //wait que espera a los 2 hijos por cada hijo Creado Anterirormente
                    } 
                    break; 
                }
                else
                    wait(NULL);//wait Para Esperar los 3 hijos Creados
            }
        }
    
    else
        wait(NULL);//wait para esperar el Hijo Creado
        
    return 0;
}