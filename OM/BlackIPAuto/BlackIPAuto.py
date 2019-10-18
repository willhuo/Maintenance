#!/user/bin/python
#coding=utf-8
#2019-10-17
#by willhuo

import time
import commands
import os
import re

print("IP Killer V1.0")
print("当前时间："+time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+"\n")

blackIpList=[]

fo=open('/etc/hosts.deny','r')
while True:
    line=fo.readline()    	
    if not line:
        break
    if line.startswith('sshd'):
        print('IP黑名单：'+line)
        blackIpMa=re.search('\d+\.\d+\.\d+\.\d+',line)
        if(blackIpMa):
            blackIpList.append(blackIpMa.group())
print("当前IP黑名单个数："+str(len(blackIpList)))

while True:
    status,result=commands.getstatusoutput('pam_tally2 --user root')
    print("脚本执行状态结果："+str(status))
    #print("脚本执行结果：\n"+result)

    ipma=re.search('\d+\.\d+\.\d+\.\d+',result)
    if ipma:
        ipstr=ipma.group()
        print("异常IP="+ipstr)
        if(ipstr not in blackIpList):
            print("自动添加IP黑名单结果："+str(os.system('echo sshd:'+ipstr+':deny>>/etc/hosts.deny')))
            blackIpList.append(ipstr)
    else:
        print("当前无异常登录IP")
        print(result)

    print("延时5S后继续\n")
    time.sleep(5)
