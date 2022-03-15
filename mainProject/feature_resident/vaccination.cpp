/*
 * @Description: 接种疫苗
 * @Author: Echooo
 * @Date: 2022-03-15
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-15
 */
#include<feature_resident/resident.h>
/*
 * 使用前提：政策包含疫苗接种
 * 参数：居民对象（或数组）
 * 使用时间和空间：每日使用一次，无空间限制
 */
void vaccination(Resident &people)
{
    if(people.getVaccine())//1为已接种，0为未接种
        return;
    else
        people.setVaccine(1);
}