#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

int activacion(float pesos[2],float x[2],float b){
    float z=0;
    float aux[2];
    float suma=0;
    for(int i=0;i<2;i++){
        aux[i]=pesos[i]*x[i];
        suma+=aux[i];
    }
    if((suma+b)>0){
        return 1;
    }
    return 0;
}


float RandomNumber(float Min, float Max)
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

/*

*/
int main()
{
    srand(static_cast <unsigned int> (time(0)));
    cout<<"Perceptron"<<endl;
    float datos [][2]={
        {0.3,0.4},
        {0.4,0.3},
        {0.3,0.2},
        {0.4,0.1},
        {0.5,0.4},
        {0.4,0.8},
        {0.6,0.8},
        {0.5,0.6},
        {0.7,0.6},
        {0.8,0.5}
    };
    
    float resultEsperados[]={0,0,0,0,0,1,1,1,1,1};
    
    float pesos[2];
    pesos[0]=RandomNumber(-1,1);
    pesos[1]=RandomNumber(-1,1);
    
    float b=RandomNumber(-1,1);
    float inicial[2]={1,1};
    
    cout<<" "<<activacion(pesos,inicial,b)<<" "<<endl;
    
    pesos[0]=RandomNumber(-1,1);
    pesos[1]=RandomNumber(-1,1);
    
    float taza_de_aprendizaje=0.01;
    int epocas=100;
    float error=0;
    float prediccion=0;
    float error_total=0;
    
    for(int i=0;i<epocas;i++){
        error_total=0;
        for(int j=0;j<10;j++){
            prediccion=activacion(pesos,datos[i],b);
            error=resultEsperados[i]-prediccion;
            error_total+=pow(error,2);
            pesos[0]+=taza_de_aprendizaje*datos[i][0]*error;
            pesos[1]+=taza_de_aprendizaje*datos[i][1]*error;
            b+=taza_de_aprendizaje*error;
        }
        cout<<error_total<<" ";
    }
    
    
    
 cout<<endl<<"Fin programa"<<endl;
    return 0;
}
