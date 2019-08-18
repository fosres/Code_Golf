package main
import("fmt";"os";"strconv")
type T struct {
	l*T
	r*T
	n*T //for level-next
	v int	
}

func insert(r**T,i int){
	if(*r==nil){*r=&T{nil,nil,i};return}
	if (i<(*r).v){insert(&((*r).l),i)
	}else{insert(&((*r).r),i)}
}


func d(r*T)int{
	d:=0;for r!=nil{r=(*r).l;d++};return d
}

var depth int = 0

func in_order(r*T,a []*T){
	if r==nil{return}
	
	depth++;in_order((*r).l,a[:]);depth--
	(*a[depth]).n=r;a[depth]=r
	depth++;in_order((*r).r,a[:]);depth--

}

func main(){v:=0;var e error;r:=&T{nil,nil,nil,0}
	for i:=1;i<len(os.Args);i++ {if v,e = strconv.Atoi(os.Args[i]);e != nil {panic(e)};if i==1{(*r).v=v}else{insert(&r,v)}
		
}
}
