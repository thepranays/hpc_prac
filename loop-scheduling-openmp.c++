#include<iostream>
#include<omp.h>
using namespace std;

void defualt_loopScheduling(){
    #pragma omp parallel for 
    for (int i = 0; i <= 20; i++)
	{
		printf("Default scheduling Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
}
void static_loopScheduling(){


    #pragma omp parallel for schedule(static,3)
    for(int i=0;i<=20;i++)
    {
		printf("Static Thread %d is running number %d\n", omp_get_thread_num(), i);
    }
}

void dynamic_loopScheduling(){
    #pragma omp parallel for schedule(dynamic, 1) 	
    for (int i = 0; i < 20; i++)
	{
		printf("Dynamic scheduling Thread %d is running number %d\n", omp_get_thread_num(), i);
	}

}

int main(){
    defualt_loopScheduling();
    cout<<"-----------------------END OF Default-------"<<endl;
    static_loopScheduling();
    cout<<"-----------------------END OF static-------"<<endl;

    dynamic_loopScheduling();
    cout<<"-----------------------END OF dynamic-------"<<endl;

    return 0;
}