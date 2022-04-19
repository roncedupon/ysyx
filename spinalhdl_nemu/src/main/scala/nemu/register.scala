package nemu
import spinal.core._
//先把那32+1个寄存器弄出来
class register extends Component{
    val io=new Bundle{
        val wdata=in UInt(64 bit)//输入的是64位的数据
        val waddr=in UInt(5 bits)//选择信号,选的是32个寄存器中的某一个
        val wen  =in Bool(1 bit)

        val rdata=out UInt(64 bit)
        val raddr=in UInt(5 bit)
        val ren=in Bool(1 bit)

        val clk=in Bool()
        val rstn=in Bool()
    }//目前认为uint和sint只是一种标记
    val registers = Vec(Reg(UInt(64 bit)),32)//创建32个寄存器
    //选择信号选择
    //registers(io.rd):=io.data_in
    val myClockDomain = ClockDomain(//创建一个时钟
    clock  = io.clk,
    reset  = io.rstn,
    config = ClockDomainConfig(
      clockEdge        = RISING,//上升沿
      resetKind        = ASYNC,//
      resetActiveLevel = LOW//低复位
    )
  )
val myArea = new ClockingArea(myClockDomain) {//整一个时钟域
    when(io.wen){
        switch(io.waddr){
            is(0){registers(0):=  io.wdata}
            is(1){registers(1):=  io.wdata}
            is(2){registers(2):=  io.wdata}
            is(3){registers(3):=  io.wdata}
            is(4){registers(4):=  io.wdata}
            is(5){registers(5):=  io.wdata}
            is(6){registers(6):=  io.wdata}
            is(7){registers(7):=  io.wdata}
            is(8){registers(8):=  io.wdata}
            is(9){registers(9):=  io.wdata}
            is(10){registers(10):=io.wdata}
            is(11){registers(11):=io.wdata}
            is(12){registers(12):=io.wdata}
            is(13){registers(13):=io.wdata}
            is(14){registers(14):=io.wdata}
            is(15){registers(15):=io.wdata}
            is(16){registers(16):=io.wdata}
            is(17){registers(17):=io.wdata}
            is(18){registers(18):=io.wdata}
            is(19){registers(19):=io.wdata}
            is(20){registers(20):=io.wdata}
            is(21){registers(21):=io.wdata}
            is(22){registers(22):=io.wdata}
            is(23){registers(23):=io.wdata}
            is(24){registers(24):=io.wdata}
            is(25){registers(25):=io.wdata}
            is(26){registers(26):=io.wdata}
            is(27){registers(27):=io.wdata}
            is(28){registers(28):=io.wdata}
            is(29){registers(29):=io.wdata}
            is(30){registers(30):=io.wdata}
            is(31){registers(31):=io.wdata}
        }
    }//需要otherwise吗?
    when(io.ren){
        switch(io.raddr){
            is(0){io.rdata:=registers(0)}
            is(1){io.rdata:=registers(1)}
            is(2){io.rdata:=registers(2)}
            is(3){io.rdata:=registers(3)}
            is(4){io.rdata:=registers(4)}
            is(5){io.rdata:=registers(5)}
            is(6){io.rdata:=registers(6)}
            is(7){io.rdata:=registers(7)}
            is(8){io.rdata:=registers(8)}
            is(9){io.rdata:=registers(9)}
            is(10){io.rdata:=registers(10)}
            is(11){io.rdata:=registers(11)}
            is(12){io.rdata:=registers(12)}
            is(13){io.rdata:=registers(13)}
            is(14){io.rdata:=registers(14)}
            is(15){io.rdata:=registers(15)}
            is(16){io.rdata:=registers(16)}
            is(17){io.rdata:=registers(17)}
            is(18){io.rdata:=registers(18)}
            is(19){io.rdata:=registers(19)}
            is(20){io.rdata:=registers(20)}
            is(21){io.rdata:=registers(21)}
            is(22){io.rdata:=registers(22)}
            is(23){io.rdata:=registers(23)}
            is(24){io.rdata:=registers(24)}
            is(25){io.rdata:=registers(25)}
            is(26){io.rdata:=registers(26)}
            is(27){io.rdata:=registers(27)}
            is(28){io.rdata:=registers(28)}
            is(29){io.rdata:=registers(29)}
            is(30){io.rdata:=registers(30)}
            is(31){io.rdata:=registers(31)}
        }
    }otherwise{
        io.rdata:=0
    }//需要otherwise吗?
  }
    
    
}
case class Color(channelWidth: Int) extends Bundle {
  val r, g, b = UInt(channelWidth bits)
}

object register {
    def main(args: Array[String]): Unit = {
       val verilog_path="/home/dy/ysyx-daiyao/spinalhdl/src/main/scala/Vcode" 
       SpinalConfig(targetDirectory=verilog_path).generateVerilog(new register)
    }
}

