#include "Mesh.h"


void Mesh::render()
{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
		glVertexPointer(3, GL_FLOAT, 0, verts);
		glNormalPointer(GL_FLOAT, 0, norms);
		glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

		// For shapes where no vertices are re-used an index array isn't required
		if (useIndexArray)
		{
			glDrawElements(faceMode, indexCount, GL_UNSIGNED_INT, indices);
		}
		else
		{
			glDrawArrays(faceMode, 0, indexCount);
		}
	
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
