//pc从内存里拿指令,并且加加
//根据mips五级流水原理图,一个输出一个输入,输入的是跳转的指令
//但是蜂鸟cpu的取指令模块有好多信号线....

package nemu
import spinal.core._

case class PaddingConfig(DATA_WIDTH: Int) {
    val Pc_Addr_Width=DATA_WIDTH
}//这里配置的是padding位宽数
class Pc(Pc_config:Pc_config) extends Component{
	val IO=new Bundle{
		val Inst=in Bits()
	}
}