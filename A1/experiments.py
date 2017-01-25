import subprocess


def timetoreadfromfile(name, writesize, blocksize):
    writetime = subprocess.check_output(
        ["./create_random_file", name, writesize, blocksize])
    speed = round(int(writesize) / (int(writetime)/ 1000000))
    return str(int(writetime) / 1000) + " milliseconds with a rate of " + str(speed) + " bytes per"


if __name__ == "__main__":
    size = "10000000"
    a = timetoreadfromfile("experiment_100.txt", size, "100")
    print("Took " + a +
          " seconds to write a file of size " + size + " with blocksize of " + "100")
    print("Took " + timetoreadfromfile("experiment_1000.txt", size, "1000") +
          " seconds to write a file of size " + size + " with blocksize of " + "1000")
    print("Took " + timetoreadfromfile("experiment_10000.txt", size, "10000") +
          " seconds to write a file of size " + size + " with blocksize of " + "10000")
    print("Took " + timetoreadfromfile("experiment_100000.txt", size, "100000") +
          " seconds to write a file of size " + size + " with blocksize of " + "100000")
    print("Took " + timetoreadfromfile("experiment_1000000.txt", size, "1000000") +
          " seconds to write a file of size " + size + " with blocksize of " + "1000000")
    print("Took " + timetoreadfromfile("experiment_1500000.txt", size, "1500000") +
          " seconds to write a file of size " + size + " with blocksize of " + "1500000")
    print("Took " + timetoreadfromfile("experiment_2000000.txt", size, "2000000") +
          " seconds to write a file of size " + size + " with blocksize of " + "2000000")
    print("Took " + timetoreadfromfile("experiment_2500000.txt", size, "2500000") +
          " seconds to write a file of size " + size + " with blocksize of " + "2500000")
    print("Took " + timetoreadfromfile("experiment_3000000.txt", size, "3000000") +
          " seconds to write a file of size " + size + " with blocksize of " + "3000000")
