package main
import("fmt";"os";"strconv")

type T struct {
	l*T
	r*T
	v int
}

func insert(r**T,i int){
	if(*r==nil){*r=&T{nil,nil,i};return}
	if (i<(*r).v){insert(&((*r).l),i)
	}else{insert(&((*r).r),i)}
}

func in_order(r*T){
	if(r==nil){return}
	in_order((*r).l)
	fmt.Printf("%d ",(*r).v)
	in_order((*r).r)
}

func pre_order(r*T){
	if(r==nil){return}
	fmt.Printf("%d ",(*r).v)
	pre_order((*r).l)
	pre_order((*r).r)
}

func post_order(r*T){
	if(r==nil){return}
	post_order((*r).l)
	post_order((*r).r)
	fmt.Printf("%d ",(*r).v)
}
func test();
func test(){}
func main(){
	v:=0;var e error;var r*T=&T{nil,nil,0}
	for i:=1;i<len(os.Args);i++{if v,e=strconv.Atoi(os.Args[i]);e!=nil{panic(e)}		
	if (i==1){r.v=v
	}else {insert(&r,v)}

}
fmt.Printf("in_order: ");in_order(r);fmt.Printf("\n")
fmt.Printf("pre_order: ");pre_order(r);fmt.Printf("\n")	
fmt.Printf("post_order: ");post_order(r);fmt.Printf("\n")	
var l [6]*T;fmt.Printf("Array of Tree pointers size: %d",len(l))
}
