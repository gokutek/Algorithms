# 有几个数据文件超过了100MB，无法push到github因此压缩了，在此解压他们。

import os

def unzip_file(zipfilename):
    txtfilepath = "Datas/"+zipfilename+".txt"
    if os.path.exists(txtfilepath):
        print(txtfilepath+" exist already,skip")
    else:
        os.system('ThirdParty\\7z\\7z.exe e Datas\\'+zipfilename+'.7z -o"Datas\\"')
        print("unzip "+zipfilename+" done")
        pass

def script_main():
    files = ["largeDG", "largeEWD", "largeEWG", "leipzig1M"]
    for file in files:
        unzip_file(file)

if __name__ == "__main__":
    script_main()
