#include <iostream>
using namespace std;

int main(){
    int c,n;
    cout<<"Ingrese la Capacidad de la Mochila: ";   cin>>c;
    cout<<"Ingrese el numero de Objetos: "; cin>>n;
    int p[n],b[n];
    for(int i=0;i<n;i++){
        cout<<"Peso del objeto "<<(i+1)<<" : "; cin>>p[i];
        cout<<"Beneficio del objeto "<<(i+1)<<" : "; cin>>b[i];
    }
    int M[n+1][c+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(i==0 || j==0){
                M[i][j]=0;
            }
            else if(p[i-1]<=j){
                M[i][j]=max(b[i-1] + M[i-1][j-p[i-1]],M[i-1][j]);
            }
            else{
                M[i][j]=M[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMayor Ganancia: "<<M[n][c];

}
