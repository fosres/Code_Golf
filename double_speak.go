package main;import ("fmt";"os");func main(){for j:=0;j<len(os.Args[1]);j++{fmt.Printf("%c%c",os.Args[1][j],os.Args[1][j])};fmt.Printf("\n");}

