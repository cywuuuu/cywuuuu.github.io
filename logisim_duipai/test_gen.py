import uuid
pa = r"E:\Desktop\logisim_duipai"
file = open(pa+r"\test_data.txt", "w")
test_str = ""
test_str += "v2.0 raw\n"
for i in range(100):
    res = str(uuid.uuid4())
    res = res.replace('-', '')
    test_str += res[:8]+"\n"
file.write(test_str)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
