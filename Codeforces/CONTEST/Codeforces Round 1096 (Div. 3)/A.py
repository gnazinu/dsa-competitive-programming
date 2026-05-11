import sys

def main():

    datos = sys.stdin.read().split()
    if not datos:
        return
    
    t = int(datos[0])
    resultados = []
    
    idx = 1
    for _ in range(t):
        x = int(datos[idx])
        y = int(datos[idx+1])
        idx += 2
        
        if x % 2 == 1 and y % 2 == 1:
            resultados.append("NO")
        else:
            resultados.append("YES")
            
    print('\n'.join(resultados))

if __name__ == '__main__':
    main()