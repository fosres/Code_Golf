package main
import(."fmt";."os";."strconv")

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

func pre_order(r*T){
	if(r==nil){return}
	Printf("%d ",(*r).v)
	pre_order((*r).l)
	pre_order((*r).r)
}

var w int = 0

func check_w(r*T,s int)bool{
	if r==nil {return false};val:=(*r).v;w+=val
	if(*r).l==nil&&(*r).r==nil&&w==s{return true}
	if check_w((*r).l,s)||check_w((*r).r,s){return true}
	w-=val;return false
}

func main(){
	s:=0;v:=0;var e error;var r*T=&T{nil,nil,0}
	for i:=1;i<len(Args);i++{if v,e=Atoi(Args[i]);e!=nil{panic(e)}		
	if (i==1){s=v}else if (i==2){(*r).v=v}else {insert(&r,v)}
}
	pre_order(r)
	Printf("%d\n",check_w(r,s))
}


