#include <iostream>
#include <queue>
using namespace std;

class Process{
    public:
    int arrivalTime;
    int burstTime;

    Process(){
        arrivalTime=-1;
        burstTime=-1;        
    }

    Process(int arrivalTime,int burstTime){
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
    }

    
};


class CPU{
    public:

    Process running;
    bool isFree;

    CPU(){
        isFree=true;
        running = Process();
    }
    

    void setRunning(Process running){
        this->running = running;
        isFree=false;
    }

    int getArrivalTime(){
        return running.arrivalTime;
    }
    int getBurstTime(){
        return running.burstTime;
    }
    int getCompletionTime(){
        int completionTime = running.arrivalTime + running.burstTime;
        return completionTime;
    }           
};

int main(){
    queue<Process> jobQueue,readyQueue;
    Process p0(0,5),p1(1,3),p2(2,8),p3(3,6);

    jobQueue.push(p0);
    jobQueue.push(p1);
    jobQueue.push(p2);
    jobQueue.push(p3);

    CPU cpu;

    int time = 0;
    while(!jobQueue.empty() || !readyQueue.empty()){
        Process p = jobQueue.front();
        
        if(p.arrivalTime <= time){
            readyQueue.push(p);
            jobQueue.pop();
        }

        if(cpu.isFree){
            cpu.setRunning(readyQueue.front());
            readyQueue.pop();
        }

        





        time++;
    }

}