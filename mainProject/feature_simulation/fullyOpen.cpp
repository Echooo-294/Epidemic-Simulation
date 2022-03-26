/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
extern int Population;//初始总人数
extern int InitInfection;//初始感染人数
extern const double StartTime;//起始时间
extern const double UpdateTime;//更新间隔时间
extern int Policy;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
extern int Day;//天数
extern double Time;//时间
QVector<Resident*> initPeople();
QVector<Resident*> initIncubation(QVector<Resident*>&);
/*
 * 使用前提：政策选择为完全开放
 * 参数：
 * 使用时间和空间：
 */
void fullyOpen()
{
    QVector<Resident*> allPeople=initPeople();//初始化人群
    QVector<Resident*> incubations=initIncubation(allPeople);//初始化感染者

}