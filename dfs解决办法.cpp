#include<stdio.h>
#include<math.h>

struct Sce
{
    char name[20] ="";//����
    double time=0;//�������ʱ��
    double ts=0;//����ʱ�䣬������8�㿪ʼ���㣬�Է���Ϊ��λ
    double te=0;//����ʱ��

    /*
        bool feve=0;//�ж��Ƿ���ҹ��ʱ�䣬������Ϊ1
        int es=0;
        int ee=0;
        */
};

double weight[41]= {-30.41402853,46.5606469,9.616872437,46.8499328,-68.80434961,87.29317547,-9.554190242,-18.65489473,5.834275922,-22.96517576,-47.11389899,
                    34.38989412,-61.58125151,-30.12595902,10.55534865,5.499279474,1.441975695,82.90397733,-5.120467567,3.918630542,-38.29658959,-10.67077425,
                    -15.41441232,6.166499101,0.983801313,-28.83759581,-30.97761515,-32.8474635,12.95259172,13.5440552,-7.609502009,25.63481276,-8.972757792,
                    32.10432593,-45.18596338,77.3869798,12.51717301,41.90980987,-12.63538519,28.06801417,-64.98958455
                   };

FILE *fin,*fout,*ffinal;

int snum=0;
double time=0;
Sce spots[45];//�ֱ�ָ��ÿһ������
double dis[45][45];//����֮��ľ�����Ϣ
bool flag[45];//��Ӧ�����Ƿ�ѡ��
int result[4][5];

int score[100];
int scoreroad[100][10];
int minscore=0;

/*int getscore(road)
{
    int length=0;
    int temp;
    while(road[length]!=0)
    {
        length++;
    }
    int i=0;
    for(i=0; i<length-1; i++)
    {
        temp+=weight[i]*spot[i].time-0.1*dis[road[i]][road[i+1]];
    }
    temp+=spot[i].time;
    return temp;
}
if(temp>minscore)
{
    for(int i=0; i<100; i++ )
    {
        if (minscore==score[i])
        {
            for(int j=0; j<10; j++)
            {
                score[i][j]=road[j];
            }
            score[i]=temp;
        }
    }
    minscore=min(score,minscore);
*/
void Min()
{

    int mini=score[1];
    for(int i=0; i<100; i++)
    {
        if(score[i]<mini)
            mini=score[i];
    }
    minscore=mini;
}
void printout(int index,int k)
{
    int temp;
    int length=0;
    int i=0;
    for(i=0; i<2; i++)
    {
        while(result[i][length]!=-1)
        {
            length++;
        }
        int j=0;
        for(j=0; j<length-1; j++)
        {
            temp+=weight[j]*spots[j].time-0.1*dis[result[i][j]][result[i][j+1]];
        }
        temp+=weight[j]*spots[j].time;
    }
    if(temp>minscore)
    {
        int mini=temp;
        for(int k=0; k<100; k++ )
        {
            if(score[k]<mini)
                mini=k;
            if (fabs(minscore-score[k])<1e-7)
            {
                int j=0;
                printf("��һ�����磺");
                fprintf(fout,"��һ�����磺");
                while(result[0][j]!=-1)
                {
                    scoreroad[k][j]=result[0][j];
                    printf("%s ",spots[result[0][j]].name);
                    fprintf(fout,"%d  ",result[0][j]);
                    j++;
                }
                j=0;
                printf("��һ�����磺");
                fprintf(fout,"��һ�����磺");
                while(result[1][j]!=-1)
                {
                    scoreroad[k][j]=result[1][j];
                    printf("%s ",spots[result[1][j]].name);
                    fprintf(fout,"%d  ",result[1][j]);
                    j++;
                }
                j=0;
                putchar('\n');
                fprintf(fout,"\n");
                /*
                        printf("�ڶ������磺");
                        fprintf(fout,"�ڶ������磺");
                        while(result[2][j]!=-1)
                        {
                            scoreroad[k][j]=result[2][j];
                            printf("%s ",spots[result[2][j]].name);
                            fprintf(fout,"%d  ",result[2][j]);
                            j++;
                        }
                        j=0;
                        printf("�ڶ������磺");
                        fprintf(fout,"�ڶ������磺");
                        while(result[3][j]!=-1)
                        {
                            scoreroad[k][j]=result[3][j];
                            printf("%s ",spots[result[3][j]].name);
                            fprintf(fout,"%ld  ",result[3][j]);
                            j++;
                        }
                        score[k]=temp;
                               j=0;


                */
                // Min();
                //break;
            }

        }
        minscore=score[mini];

    }
    /*

            int i=0;
            printf("��һ�����磺");
            fprintf(fout,"��һ�����磺");
            while(result[0][i]!=-1)
            {
                printf("%s  ",spots[result[0][i]].name);
                fprintf(fout,"%s  ",spots[result[0][i]].name);
                i++;
            }
            i=0;

            printf("���磺");
            fprintf(fout,"���磺");
            while(result[1][i]!=-1)
            {
                printf("%s  ",spots[result[1][i]].name);
                fprintf(fout,"%s  ",spots[result[1][i]].name);
                i++;
            }
            i=0;

            printf("�ڶ������磺");
            fprintf(fout,"�ڶ������磺");
            while(result[2][i]!=-1)
            {
                printf("%s  ",spots[result[2][i]].name);
                fprintf(fout,"%s  ",spots[result[2][i]].name);
                i++;
            }
            i=0;

            printf("���磺");
            fprintf(fout,"���磺");
            while(result[3][i]!=-1)
            {
                printf("%s  ",spots[result[3][i]].name);
                fprintf(fout,"%s  ",spots[result[3][i]].name);
                i++;
            }
            i=0;
    */
    putchar('\n');
    fprintf(fout,"\n");

}
void dfs(int index,double totaltime,int k)//index��ʾģ������,0Ϊ���磬1Ϊ����,si��ʾ  kΪ��ǰ��������
{
    if(index==2)
    {
        //putchar('\n');
        //fprintf(fout,"\n");
        printout(index,k);
        return ;
    }
    else
    {
        bool f=false;
        for(int i=0; i<snum; i++)
        {
            if(flag[i]==true)
                continue;
            else
            {
                if(k==0)
                {
                    flag[i]=true;
                    result[index][k]=i;
                    dfs(index,totaltime,k+1);
                    flag[i]=false;
                    result[index][k]=-1;
                    f=true;
                }
                else if(totaltime+dis[result[index][k-1]][i] + spots[i].time +0.5*k<= 4)
                {
                    flag[i]=true;
                    result[index][k]=i;
                    dfs(index,totaltime+dis[ result[index][k-1] ][i] + spots[i].time,k+1);
                    flag[i]=false;
                    result[index][k]=-1;
                    f=true;
                }
            }
        }
        if(f==false)
        {
            dfs(index+1,0,0);
        }

    }

}

/*
void dfs(int index,double totaltime,int k)//index��ʾģ������,0Ϊ���磬1Ϊ����,si��ʾ  kΪ��ǰ��������
{
    if(index==4)
    {
        //putchar('\n');
        //fprintf(fout,"\n");
        printout(index,k);
        return ;
    }
    else
    {
        bool f=false;
        for(int i=0; i<snum; i++)
        {
            if(flag[i]==true)
                continue;
            else
            {
                if(k==0)
                {
                    flag[i]=true;
                    result[index][k]=i;
                    dfs(index,totaltime,k+1);
                    flag[i]=false;
                    result[index][k]=-1;
                    f=true;
                }
                else if(totaltime+dis[result[index][k-1]][i] + spots[i].time +0.5*k<= 4)
                {
                    flag[i]=true;
                    result[index][k]=i;
                    dfs(index,totaltime+dis[ result[index][k-1] ][i] + spots[i].time,k+1);
                    flag[i]=false;
                    result[index][k]=-1;
                    f=true;
                }
            }
        }
        if(f==false)
        {
            dfs(index+1,0,0);
        }

    }

}
*/
/*void dfs(int index,double totaltime,int k)//index��ʾģ������,0Ϊ���磬1Ϊ����,si��ʾ  kΪ��ǰ��������
{
    int i=0;
    for(i=0; i<40; i++)
    {
        if(flag[i]== true ) continue;
        else
        {
            if(k==0) result[k]=i;
            else
            {
                if(totaltime+dis[ result[k-1] ][i] + spots[i].time > 3+0.5*index )
                {
                    printout(result,si);
                    for(int m=0; m<10; m++)
                    {
                        result[m]=0;
                    } //ÿ�������һ��
                    if(si==0) dfs(si+1,totaltime,k); //���������ж��Ƿ�����
                    else return;
                }
                else
                {
                    result[k]=i;
                    totaltime+=dis[ result[k-1] ][i]+spots[i].time;
                    dfs(si, totaltime,k+1);
                }
            }
        }
    }
}*/


/*void Init()
{
    printf("�����뾰�������");
    scanf("%d",&snum);
    printf("����������ÿ����������ƣ���������ʱ�䣬����ʱ���Լ��ر�ʱ��\n");
    for(int i=0; i<snum; i++)
    {
        scanf("%s",spots[i].name);
        scanf("%lf",&spots[i].time);
        scanf("%d%d",&spots[i].ts,&spots[i].te);
    }


    printf("���Ծ������ʽ���뾰������֮��ľ���\n");
    for(int i=0; i<snum; i++)
        for(int j=0; j<snum; j++)
        {
            scanf("%lf",&dis[i][j]);
        }
}*/




void fInit()
{
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    ffinal=fopen("final.txt","w");
    char name[50];
    int t;
    int top,tend;

    fscanf(fin,"%d",&snum);

    for(int i=0; i<snum; i++)
    {
        fscanf(fin,"%s",spots[i].name);
        fscanf(fin,"%lf",&spots[i].time);
        fscanf(fin,"%lf%lf",&spots[i].ts,&spots[i].te);
    }

    for(int i=0; i<snum; i++)
        for(int j=0; j<snum; j++)
        {
            fscanf(fin,"%lf",&dis[i][j]);
        }

    for(int i=0; i<4; i++)
        for(int j=0; j<5; j++)
            result[i][j]=-1;
}

int main()
{
    for(int i=0; i<100; i++)
    {
        for (int j=0; j<100;j++)
        {
        scoreroad[i][j]=-1;
        }
    }
    fInit();
    dfs(0,0,0);

    fclose(fin);
    fclose(fout);

    for(int i=0; i<100; i++)
    {
        fprintf(ffinal,"%d ·�ߣ�",score[i]);
        int j=0;
        while(scoreroad[i][j]!=-1)
        {
            fprintf(ffinal,"%d ",scoreroad[i][j]);
            j++;
        }
        fprintf(ffinal,"\n");
    }

    fclose(ffinal);
    return 0;
}
