/*
 * @Description: 病毒自然增长
 * @Author: Echooo
 * @Date: 2022-03-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-12 21:09
 */

//后面添加病毒类作为参数再修改
void virusGrowth(Resident &people)
{
    double density=people.getVirusDensity();
    double growthRate=0.03;
    int incubationPeriod=10;
    double boundary1=incubationPeriod*growthRate;//潜伏与出症状的密度界限
    if(density>0&&density<boundary1)
        people.setVirusDensity(density+growthRate);
    else if(density<1&&density>=boundary1)
        people.setVirusDensity(density+growthRate);
}