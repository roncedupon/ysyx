package nemu_v2
import spinal.core._
object PC_register{

}
class PC() extends Component{
	val Io=new Bundle{
		val pc_in=in
	}
}