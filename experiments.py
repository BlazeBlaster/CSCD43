import subprocess


def timetoreadfromfile(name, writesize, blocksize):
    writetime = subprocess.check_output(["./create_random_file", name, writesize, blocksize])
    return str (int(writetime) / 1000000)


if __name__ == "__main__":
    size = "10000000"
    print("Took " + timetoreadfromfile("experiment.txt", size, "100") + " seconds to write a file of size " + size + " with blocksize of " + "100")
    print("Took " + timetoreadfromfile("experiment.txt", size, "200") + " seconds to write a file of size " + size + " with blocksize of " + "200")
    print("Took " + timetoreadfromfile("experiment.txt", size, "350") + " seconds to write a file of size " + size + " with blocksize of " + "350")
    print("Took " + timetoreadfromfile("experiment.txt", size, "500") + " seconds to write a file of size " + size + " with blocksize of " + "500")
    print("Took " + timetoreadfromfile("experiment.txt", size, "750") + " seconds to write a file of size " + size + " with blocksize of " + "750")
    print("Took " + timetoreadfromfile("experiment.txt", size, "1000") + " seconds to write a file of size " + size + " with blocksize of " + "1000")
    print("Took " + timetoreadfromfile("experiment.txt", size, "1250") + " seconds to write a file of size " + size + " with blocksize of " + "1250")
    print("Took " + timetoreadfromfile("experiment.txt", size, "1500") + " seconds to write a file of size " + size + " with blocksize of " + "1500")
    print("Took " + timetoreadfromfile("experiment.txt", size, "2000") + " seconds to write a file of size " + size + " with blocksize of " + "2000")
    print("Took " + timetoreadfromfile("experiment.txt", size, "2500") + " seconds to write a file of size " + size + " with blocksize of " + "2500")
    print("Took " + timetoreadfromfile("experiment.txt", size, "3000") + " seconds to write a file of size " + size + " with blocksize of " + "3000")



