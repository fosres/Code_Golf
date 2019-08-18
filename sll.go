package main
import ("fmt";"os";"strconv")
type L struct {
	val int
	n*L			
}

func insert(n*L,i int) *L{
	for n.n!=nil {n=n.n}
	n.n = &L{i,nil}
	n=n.n
	return n
}

func delete(n**L,i int) *L{
	r:=n;for (*n)!=nil {if (*n).val==i{*n=(*n).n;break};n=&((*n).n)};return *r
}

func main() {
	t:=&L{0,nil};o:=t;i:=1;v:=0;var e error
	for i<len(os.Args){if v,e = strconv.Atoi(os.Args[i]);e!=nil{panic(e)}

		t=insert(t,v);i++;
	}

	t=o.n;
	for t!=nil {fmt.Printf("%d ",t.val);t=t.n}
	
	if v,e = strconv.Atoi(os.Args[1]);e!=nil{panic(e)}

	delete(&o.n,v)

	t=o.n;fmt.Printf("\n")
	for t!=nil {fmt.Printf("%d ",t.val);t=t.n}
}
