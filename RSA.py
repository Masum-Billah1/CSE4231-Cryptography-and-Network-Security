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

for i in range(len(blocks)):
    encrypt.append(pow(int(blocks[i]),e)%product)

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