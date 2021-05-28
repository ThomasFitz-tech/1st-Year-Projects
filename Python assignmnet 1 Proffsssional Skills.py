vat = 0
numVat = 0
totalVat = 0

def main():

    salesfigures = []
    salefigvat = []
    total =0
    sf=0

    sf = int(input("enter sales figure"))

    while(sf != -1):
        salesfigures.append(sf)

        salefigvat.append(addVAT(sf))
        total += salefigvat[-1]
        sf = int(input("enter sales figure"))
    

    print("the sales you entered were : %s\nthe sales inclduing VAT were: %s"%(salesfigures,salefigvat))
    print("total vat charged=",totalVat)
    print("total sales for this period is:",total)

def addVAT(sf):
    global vat
    global numVat
    global totalVat

    vat = sf * 0.23
    numVat = sf + vat
    totalVat += vat
    
    return numVat

main()
