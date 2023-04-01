#include "Difficult.h"

DifCell* findNode(DifCell** a, int y, int x) {
	if (y < 0 || y > HEIGHT - 1 || x < 0 || x > WIDTH - 1) {
		return NULL;
	}
	DifCell* tmp = a[y];
	while (tmp != NULL) {
		if (tmp->xCol == x) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void ::deleteNode(DifCell** a, int y, int x, char bg[][41]) {
	DifCell* p = findNode(a, y, x);
	//	Trường hợp node ở vị trí đầu
	if (x == 0) {
		if (a[y]->next == NULL) {
			a[y]->deleteCell();
			if (a[y]->xCol < 4) {
				displayBackground(bg, a[y]->xCol, y);
			}
			a[y] = NULL;
			return;
		}

		a[y]->c = p->next->c;
		p = a[y]->next;
		if (p->next == NULL) {
			p->deleteCell();
			if (p->xCol < 4) {
				displayBackground(bg, p->xCol, y);
			}
			delete p;
			a[y]->next = NULL;
		}
		else {
			while (p->next->next != NULL) {
				p->c = p->next->c;
				p = p->next;
			}
			p->c = p->next->c;
			p->next->deleteCell();
			if (p->next->xCol < 4) {
				displayBackground(bg, p->next->xCol, p->next->yRow);
			}
			delete p->next;
			p->next = NULL;
		}
	}
	// trường hợp node ở giữa
	else if (p->next != NULL) {
		while (p->next->next != NULL) {
			p->c = p->next->c;
			p = p->next;
		}
		p->c = p->next->c;
		p->next->deleteCell();
		if (p->next->xCol < 4) {
			displayBackground(bg, p->next->xCol, p->next->yRow);
		}
		delete p->next;
		p->next = NULL;
	}
	// trường hợp node ở cuối dòng
	else {
		p->deleteCell();
		if (p->xCol < 4) {
			displayBackground(bg, p->xCol, p->yRow);
		}
		delete p;
		p = findNode(a, y, x - 1);
		p->next = NULL;
	}
}
