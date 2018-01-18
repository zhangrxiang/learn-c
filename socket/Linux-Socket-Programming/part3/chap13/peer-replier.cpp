/* peer-replier.cpp
 *
 * Copyright (c) 2000 Sean Walton and Macmillan Publishers.  Use may be in
 * whole or in part in accordance to the General Public License (GPL).
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/

/*****************************************************************************/
/*** peer-replier.cpp                                                      ***/
/***                                                                       ***/
/*** Demonstrates how to create a datagram server.                         ***/
/*****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "socket.h"

int main(int count, char *strings[])
{
	if ( count != 2 )
	{
		printf("usage: %s <addr:port>\n", strings[0]);
		exit(1);
	}

	HostAddress addr(strings[1]);
	HostAddress peer;
	try
	{
		Datagram client(addr);
		TextMessage msg(1024);
		do
		{
			client.Receive(peer, msg);
			printf("msg=%s from %s", msg.GetBuffer(), peer.GetHost());
			client.Send(peer, msg);
		}
		while ( strcmp(msg.GetBuffer(), "bye\n") != 0 );
	}
	catch (Exception& err)
	{
		err.PrintException();
	}
	catch (...)
	{
		fprintf(stderr, "Unknown error\n");
	}
	return 0;
}
