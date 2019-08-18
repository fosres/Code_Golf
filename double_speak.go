package main;import ("fmt";"os");func main(){for i:=1;i<len(os.Args);i++{for j:=0;j<len(os.Args[i]);j++ {fmt.Printf("%c%c",os.Args[i][j],os.Args[i][j])}};fmt.Printf("\n");}

