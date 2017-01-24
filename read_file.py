import subprocess


def timetoreadfromfile(name, blocksize):
    writetime = subprocess.check_output(["./get_histogram", name, blocksize])
    return str (int(writetime) / 1000000)


if __name__ == "__main__":
    print("Took " + timetoreadfromfile("experiment_100.txt", "100") + " seconds to read experiment_100.txt with blocksize of " + "100")
    print("Took " + timetoreadfromfile("experiment_100.txt", "350") + " seconds to read experiment_100.txt with blocksize of " + "350")
    print("Took " + timetoreadfromfile("experiment_100.txt", "500") + " seconds to read experiment_100.txt with blocksize of " + "500")
    print("Took " + timetoreadfromfile("experiment_100.txt", "750") + " seconds to read experiment_100.txt with blocksize of " + "750")
    print("Took " + timetoreadfromfile("experiment_100.txt", "1000") + " seconds to read experiment_100.txt with blocksize of " + "1000")
    print("Took " + timetoreadfromfile("experiment_100.txt", "1250") + " seconds to read experiment_100.txt with blocksize of " + "1250")
    print("Took " + timetoreadfromfile("experiment_100.txt", "1500") + " seconds to read experiment_100.txt with blocksize of " + "1500")
    print("Took " + timetoreadfromfile("experiment_100.txt", "2000") + " seconds to read experiment_100.txt with blocksize of " + "2000")
    print("Took " + timetoreadfromfile("experiment_100.txt", "2500") + " seconds to read experiment_100.txt with blocksize of " + "2500")
    print("Took " + timetoreadfromfile("experiment_100.txt", "3000") + " seconds to read experiment_100.txt with blocksize of " + "3000")



