using Modbus.Device;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.Diagnostics;

namespace Datalogger
{
    class Program
    {
        private static SerialPort port;
        private static ModbusSerialMaster mstr;
        private static long timestam1, timestamp2;

        static void Main(string[] args)
        {

            port = new SerialPort();
            port.PortName = "COM2";
            port.BaudRate = 19200;
            port.DataBits = 8;
            port.StopBits = StopBits.One;
            port.Parity = Parity.None;
            port.ReadTimeout = 2000;
            port.WriteTimeout = 100;

            mstr = ModbusSerialMaster.CreateRtu(port);

            while (true)
            {
                try
                {
                    if (!port.IsOpen)
                    {
                        port.Open();
                    }

                    Console.WriteLine("\n\nPorta Aberta");

                    for (ushort cont = 0; cont < 4; ++cont)
                    {
                        timestam1 = 0;
                        timestamp2 = 0;
                        Console.WriteLine("Leitura do endereco " + cont * 40);
                        timestam1 = DateTime.Now.Millisecond;
                        ushort[] resp = mstr.ReadHoldingRegisters(1, (ushort)(40 * cont), 40);
                        timestamp2 = DateTime.Now.Millisecond;
                        Console.WriteLine(string.Join(" ", resp));
                        Console.WriteLine("Tempo: " + (timestamp2 - timestam1) + "ms");
                    }
                }

                catch (Exception ex)
                {
                    Console.WriteLine(ex.ToString());
                }

                finally
                {
                    if (port.IsOpen)
                    {
                        port.Close();
                        Console.WriteLine("Porta Fechada");
                    }
                }
            }
        }

        private static String GetIndex(ushort[] arr)
        {
            return ((byte)((arr[3] & 0xFF00) >> 8)).ToString();
        }
    }
}