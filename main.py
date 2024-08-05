import string

ALPHABET = string.ascii_lowercase

s = "ifailuhkqq" # chuỗi đầu vào

signatures = {} # mảng với từng kí tự?!

signature = [0 for _ in ALPHABET] # mảng đặc trưng

for letter in s:
    signature[ord(letter)-ord(ALPHABET[0])] += 1   #  cữ mỗi lần trùng char -> thêm vào mảng

# -> được mảng counting chuỗi kí tự
# -> mảng trên được coi như "signatures hashmap"


# duyệt lại qua ss
for start in range(len(s)):
    for finish in range(start, len(s)):
        # initialize substring signature
        signature = [0 for _ in ALPHABET]  # lại khởi tạo lại mảng signature bằng full 0
        for letter in s[start:finish+1]:
            signature[ord(letter)-ord(ALPHABET[0])] += 1
        # tuples are hashable in contrast to lists
        signature = tuple(signature)
        signatures[signature] = signatures.get(signature, 0) + 1


# công thức
res = 0
for count in signatures.values():
    res += count*(count-1)/2
print(res)



