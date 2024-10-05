def power_mod(block,binary,product):
    number = int(block)
    array = []
    array.append(number % product)
    for i in range(1,len(binary)):
        array.append(pow(array[i-1],2)% product)

    result = 1
    for i in range(len(binary)):
        if(binary[i]=='1'):
            result = (result*array[i])% product
    return result


with open('rsa.txt', 'r') as file:
    single_line = file.readline()
print("Message: ",single_line)

blocks = []
encrypt = []
for i in range(0, len(single_line), 3):
    blocks.append(single_line[i:i+3])

e = int(79)
p = int(47)
q = int(71)
product = p*q
binary = bin(e)[2:][::-1]

for i in range(len(blocks)):
    encrypt.append(power_mod(blocks[i],binary,product))

print("Encryption: ",end='')
for i in range(len(encrypt)):
    print(encrypt[i],end='')
print()

#decryption
d = pow(e, -1, ((p-1)*(q-1)))
print("Decription: ",end='')
for i in range(len(encrypt)):
    decrypt = pow(encrypt[i],d)%product
    print(decrypt,end='')
