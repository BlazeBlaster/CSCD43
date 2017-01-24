import subprocess


def timetoreadfromfile(name, writesize, blocksize):
    writetime = subprocess.check_output(
        ["./create_random_file", name, writesize, blocksize])
    return str(int(writetime) / 1000000)


if __name__ == "__main__":
    size = "10000000"
    print("Took " + timetoreadfromfile("experiment_100.txt", size, "100") +
          " seconds to write a file of size " + size + " with blocksize of " + "100")
    print("Took " + timetoreadfromfile("experiment_200.txt", size, "200") +
          " seconds to write a file of size " + size + " with blocksize of " + "200")
    print("Took " + timetoreadfromfile("experiment_400.txt", size, "400") +
          " seconds to write a file of size " + size + " with blocksize of " + "400")
    print("Took " + timetoreadfromfile("experiment_800.txt", size, "800") +
          " seconds to write a file of size " + size + " with blocksize of " + "800")
    print("Took " + timetoreadfromfile("experiment_1600.txt", size, "1600") +
          " seconds to write a file of size " + size + " with blocksize of " + "1600")
    print("Took " + timetoreadfromfile("experiment_3200.txt", size, "3200") +
          " seconds to write a file of size " + size + " with blocksize of " + "3200")
    print("Took " + timetoreadfromfile("experiment_6400.txt", size, "6400") +
          " seconds to write a file of size " + size + " with blocksize of " + "6400")
    print("Took " + timetoreadfromfile("experiment_12800.txt", size, "12800") +
          " seconds to write a file of size " + size + " with blocksize of " + "12800")
    print("Took " + timetoreadfromfile("experiment_25600.txt", size, "25600") +
          " seconds to write a file of size " + size + " with blocksize of " + "25600")
    print("Took " + timetoreadfromfile("experiment_51200.txt", size, "51200") +
          " seconds to write a file of size " + size + " with blocksize of " + "51200")
    print("Took " + timetoreadfromfile("experiment_100000.txt", size, "100000") +
          " seconds to write a file of size " + size + " with blocksize of " + "100000")
    print("Took " + timetoreadfromfile("experiment_200000.txt", size, "200000") +
          " seconds to write a file of size " + size + " with blocksize of " + "200000")
    print("Took " + timetoreadfromfile("experiment_300000.txt", size, "300000") +
          " seconds to write a file of size " + size + " with blocksize of " + "300000")
