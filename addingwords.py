cmds = []

while True:
    try:
        line = input()
        cmds.append(line)
    except EOFError:
        break
    
defs = {}    

for cmd in cmds:
    words = cmd.split()
    if words[0] == "def":
        defs[words[1]] = int(words[2])
    if words[0] == "clear":
        defs.clear()
    if words[0] == "calc":
        s = 0
        sign = '+'
        unknown = False
        for i in range(1, len(words)):
            print(words[i] + ' ', end='')
            if words[i] != '+' and words[i] != '-' and words[i] != '=' and unknown == False:
                if words[i] in defs.keys():
                    if(sign == '+'):
                        s += int(defs[words[i]])
                    else:
                        s -= int(defs[words[i]])
                else:
                    unknown = True
            else:
                if words[i] == '=':
                    break
                else:
                    sign = words[i]
        if unknown == False:
            if s not in defs.values():
                print("unknown")
            else:
                for key in defs.keys():
                    if s == defs[key]:
                        print(key)
        else:
            print("unknown")
